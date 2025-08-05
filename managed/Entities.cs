namespace SwiftlyS2.API.Extensions.SDKTools
{
    public class Entities
    {
        public static void ListenEntityTouchUse(string class_name)
        {
            Internal_API.Invoker.CallNative("_G", "ListenEntityTouchUse", Internal_API.CallKind.Function, class_name);
        }

        public static void RemoveListenEntityTouchUse(string class_name)
        {
            Internal_API.Invoker.CallNative("_G", "RemoveListenEntityTouchUse", Internal_API.CallKind.Function, class_name);
        }
    }
}
