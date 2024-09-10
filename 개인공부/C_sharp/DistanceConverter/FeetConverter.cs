using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DistanceConverter
{
    public static class FeetConverter
    {
        private static readonly double ratio = 0.3048;
        public static double ToMeter(int feet)
        {
            return feet * ratio;
        }

        public static double FromMeter(int meter)
        {
            return meter / ratio;
        }
    }
}
