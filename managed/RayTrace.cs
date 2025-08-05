using SwiftlyS2.Internal_API;
using static SwiftlyS2.API.Extensions.SDKTools.RayTraceSDK;
using static SwiftlyS2.API.SDK.CoreClasses;

namespace SwiftlyS2.API.Extensions.SDKTools
{
    public class RayTrace
    {
        private static IntPtr _ctx = IntPtr.Zero;

        private static void InitializeContext()
        {
            if (_ctx != IntPtr.Zero) return;
            _ctx = Invoker.CallNative<IntPtr>("RayTrace", "RayTrace", CallKind.ClassFunction);
        }
        public static void TracePlayerBBox(Vector start, Vector end, BBox bounds, CTraceFilter filter, trace_t trace_out)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("RayTrace", "TracePlayerBBox", Internal_API.CallKind.ClassFunction, _ctx, start, end, bounds, filter, trace_out);
        }
        public static void TraceShape(Vector start, Vector end, Ray_t ray, CTraceFilter filter, trace_t trace_out)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("RayTrace", "TraceShape", Internal_API.CallKind.ClassFunction, _ctx, start, end, ray, filter, trace_out);
        }
    }
}