using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;
using System.Drawing.Imaging;

namespace UPPER
{
    /// <summary>
    /// 用于生成RealTime曲线图的类
    /// </summary>
    /// 
    public partial class RTGraphGenerator
    {
        public const int AXIS_RANGE_X_DEFAULT = 20000;
        public const int AXIS_RANGE_X_MINIMUM = 1000;
        public const double AXIS_RANGE_Y_MINIMUM = 10;
        // 高度
        private int graph_height = 320;
        // 宽度
        private int graph_width = 320;
        // 背景色
        private Color back_color = Color.Black;
        // 前景色
        private Color fore_color = Color.Aqua;
        // 横坐标范围(默认方向：左为0，从左到右为正)
        private int axis_range_x = AXIS_RANGE_X_DEFAULT;
        private int axis_range_x_bysetting = AXIS_RANGE_X_DEFAULT;
        // 纵坐标范围(默认方向：下为0，从下到上为正)
        private double axis_range_y = AXIS_RANGE_Y_MINIMUM;
        private double axis_range_y_bysetting = AXIS_RANGE_Y_MINIMUM;
        // 生成图形
        public Image generateImage(Dictionary<long, double> dataIn)
        {
            // 复制所有横坐标的值
            List<long> keys = new List<long>(dataIn.Keys);
            keys.Sort();
            long xmin = 0;
            long xmax = keys.Last();
            // 序列里面存在超过定义的X轴范围的数，移除之。
            while ((keys.Count > 0) && (keys.First() < xmax - axis_range_x))
            {
                keys.RemoveAt(0);
                xmin = keys.First();
            }
            // X 轴数据已经处理好了。
            // 准备处理Y轴数据
            double ymind = double.MaxValue;
            double ymaxd = double.MinValue;
            foreach (long k in keys)
            {
                double yvalue;
                dataIn.TryGetValue(k, out yvalue);
                ymind = ymind > yvalue ? yvalue : ymind;
                ymaxd = ymaxd < yvalue ? yvalue : ymaxd;
            }
            // 计算出Y轴的范围
            this.AxisRangeY = ymaxd - ymind;
            // 到目前为止 横坐标范围已定xmin~xmax，纵坐标范围已定ymin~ymax。在生成图像的时候需要进行映射。
            // 如果图像的最大高度差不足最小要求的高度差，则让图像尽可能的放在中间，而不是靠下。
            Bitmap img = new Bitmap(graph_width, graph_height);
            Graphics graph = Graphics.FromImage(img);
            Pen pen = new Pen(fore_color);
            int g_x, g_y;
            graph.Clear(back_color);
            // 画点
            foreach (long xvalue in keys)
            {
                double yvalue;
                dataIn.TryGetValue(xvalue, out yvalue);
                this.convert_axis_2_graph(out g_x, out g_y, xvalue - xmin, yvalue - ymind);
                graph.DrawEllipse(pen, g_x - 2, g_y - 2, 5, 5);
            }
            // 划横线
            double a_x = 0, a_y = 0;
            // 找一个这个范围内看上去最整的数
            double ygmax = (ymaxd + (double)(AxisRangeY - axis_range_y_bysetting) / 2);
            double ygmin = ygmax - AxisRangeY;
            // 找适合的数量级
            a_x = 9.1;
            while (a_x > 0)
            {
                if (AxisRangeY > Math.Pow(10, (int)a_x))
                {
                    break;
                }
                a_x--;
            }
            a_x = (int)a_x;
            // 
            if (AxisRangeY > 5 * Math.Pow(10, a_x))
            {
                a_x = 5 * Math.Pow(10, a_x);
            }
            else if (AxisRangeY > 2 * Math.Pow(10, a_x))
            {
                a_x = 2 * Math.Pow(10, a_x);
            }
            else
            {
                a_x = (Math.Pow(10, a_x));
            }
            // 找基准纵坐标
            if (ygmax >= 0 && ygmin <= 0)
            {
                a_y = 0;
            }
            else
            {
                // 距离底线最近的"整"线
                a_y = ygmin / (a_x / 5);
                int tmp = (int)a_y;
                a_y = a_x / 5 * tmp;
                while (a_y < ygmin)
                {
                    a_y += (a_x / 5);
                }
            }
            // 基准纵坐标a_y找到之后
            // 开始划线
            double line_y = a_y;
            this.convert_axis_2_graph(out g_x, out g_y, 0, line_y - ymind);
            graph.DrawLine(new Pen(Color.White), 0, g_y, graph_width, g_y);
            graph.DrawString(String.Format("{0}", line_y), new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134))), new Pen(Color.Orange).Brush, 0, g_y - 12);
            while (line_y < ymaxd)
            {
                line_y += a_x / 5;
                this.convert_axis_2_graph(out g_x, out g_y, 0, line_y - ymind);
                graph.DrawLine(new Pen(Color.Gray), 0, g_y, graph_width, g_y);
                graph.DrawString(String.Format("{0}", line_y), new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134))), new Pen(Color.Orange).Brush, 0, g_y - 12);

            }
            line_y = a_y;
            while (line_y > ymind)
            {
                line_y -= a_x / 5;
                this.convert_axis_2_graph(out g_x, out g_y, 0, line_y - ymind);
                graph.DrawLine(new Pen(Color.Gray), 0, g_y, graph_width, g_y);
                graph.DrawString(String.Format("{0}", line_y), new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134))), new Pen(Color.Orange).Brush, 0, g_y - 12);
            }
            return img;
        }
    }
}