using System.Drawing;
using System.Drawing.Imaging;
namespace UPPER
{
    public partial class RTGraphGenerator
    {
        private double k_x = 0;
        private double k_y = 0;

        public int GraphHeight
        {
            get
            {
                return graph_height;
            }
            set
            {
                graph_height = value;
                k_y = (double)GraphHeight / AxisRangeY;
            }
        }
        public int GraphWidth
        {
            get
            {
                return graph_width;
            }
            set
            {
                graph_width = value;
                k_x = (double)GraphWidth / AxisRangeX;
            }
        }
        public Color BackColor
        {
            get
            {
                return back_color;
            }
            set
            {
                back_color = value;
            }
        }
        public Color ForeColor
        {
            get
            {
                return fore_color;
            }
            set
            {
                fore_color = value;
            }
        }
        public int AxisRangeX
        {
            get
            {
                return axis_range_x;
            }
            set
            {
                axis_range_x = value < AXIS_RANGE_X_MINIMUM ? AXIS_RANGE_X_MINIMUM : value;
                axis_range_x_bysetting = value;
                k_x = (double)GraphWidth / AxisRangeX;
            }
        }
        double AxisRangeY
        {
            get
            {
                return axis_range_y;
            }
            set
            {
                axis_range_y = value < AXIS_RANGE_Y_MINIMUM ? AXIS_RANGE_Y_MINIMUM : value;
                axis_range_y_bysetting = value;
                k_y = (double)GraphHeight / AxisRangeY;
            }
        }
        // 用于坐标转换用
        // 将数学坐标系的点转换到图像坐标上面
        // a_x a_y 数学坐标 
        // g_x g_y 图像坐标
        void convert_axis_2_graph(out int g_x, out int g_y, double a_x, double a_y)
        {
            g_x = (int)(this.k_x * a_x);
            g_y = (int)(graph_height - this.k_y * (a_y + (double)(AxisRangeY - axis_range_y_bysetting) / 2));
        }
    }
}
