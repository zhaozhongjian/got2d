#pragma once
#include <g2dconfig.h>

namespace g2d
{
	// 消息类型
	enum class G2DAPI MessageEvent : int
	{
		Invalid,					// 未知消息
		LostFocus,					// 切换窗口的时候
		MouseMove,					// 光标移动
		MouseButtonDown,			// 鼠标按钮被按下
		MouseButtonUp,				// 鼠标按钮释放
		MouseButtonDoubleClick,		// 鼠标按钮双击
		KeyDown,					// 键盘按钮被按
		KeyUp,						// 键盘按钮释放
	};


	// 输入设备，事件来源
	enum class G2DAPI MessageSource : int
	{
		Mouse, Keyboard, None
	};

	// 鼠标按键标识
	enum class G2DAPI MouseButton : int
	{
		Left = 0, Middle = 1, Right = 2, None = 3
	};

	constexpr int NUMPAD_OFFSET = 0x1000;

	enum class G2DAPI KeyCode : int
	{
		Invalid = 0,

		// 功能按键
		Escape,
		Enter = '\n',
		Space = ' ',
		Tab = '\t',
		Control,
		Shift,
		Alt,
		Capital,
		Backspace,
		Pause,
		PageUp, PageDown, Home, End, Insert, Delete,
		ArrowLeft, ArrowUp, ArrowRight, ArrowDown,

		// F区
		F1 = 0x1101, F2 = 0x1102, F3 = 0x1103,
		F4 = 0x1104, F5 = 0x1105, F6 = 0x1106,
		F7 = 0x1107, F8 = 0x1108, F9 = 0x1109,
		F10 = 0x110A, F11 = 0x110B, F12 = 0x110C,

		// 数字 equals to '0' to '9'
		Num0 = '0', Num1 = '1', Num2 = '2', Num3 = '3', Num4 = '4',
		Num5 = '5', Num6 = '6', Num7 = '7', Num8 = '8', Num9 = '9',

		// 小键盘 equals to 0x100+'0' to 0x100+'9'
		Numpad0 = '0' + NUMPAD_OFFSET, Numpad1 = '1' + NUMPAD_OFFSET, Numpad2 = '2' + NUMPAD_OFFSET,
		Numpad3 = '3' + NUMPAD_OFFSET, Numpad4 = '4' + NUMPAD_OFFSET, Numpad5 = '5' + NUMPAD_OFFSET,
		Numpad6 = '6' + NUMPAD_OFFSET, Numpad7 = '7' + NUMPAD_OFFSET, Numpad8 = '8' + NUMPAD_OFFSET,
		Numpad9 = '9' + NUMPAD_OFFSET, NumpadLock,
		NumpadDecimal = '.' + NUMPAD_OFFSET, NumpadEnter = '\n' + NUMPAD_OFFSET,
		NumpadAdd = '+' + NUMPAD_OFFSET, NumpadSub = '-' + NUMPAD_OFFSET,
		NumpadMul = '*' + NUMPAD_OFFSET, NumpadDiv = '/' + NUMPAD_OFFSET,

		// 主要键区 equals to 'A' to 'Z'
		KeyA = 'A', KeyB = 'B', KeyC = 'C', KeyD = 'D', KeyE = 'E', KeyF = 'F', KeyG = 'G',
		KeyH = 'H', KeyI = 'I', KeyJ = 'J', KeyK = 'K', KeyL = 'L', KeyM = 'M', KeyN = 'N',
		KeyO = 'O', KeyP = 'P', KeyQ = 'Q', KeyR = 'R', KeyS = 'S', KeyT = 'T',
		KeyU = 'U', KeyV = 'V', KeyW = 'W', KeyX = 'X', KeyY = 'Y', KeyZ = 'Z',

		// 特殊键位
		OMETilde = '`', OEMSub = '-', OEMAdd = '+', OEMLBracket = '[', OEMRBracket = ']', OEMRSlash = '\\',
		OEMColon = ';', OEMQuote = '\'', OEMComma = ',', OEMPeriod = '.', OEMSlash = '/',
	};

	// 系统使用的事件，请使用TranslateMessage翻译系统事件
	// 一般只有引擎内部会构造虚拟消息
	class G2DAPI Message
	{
	public:
		const MessageEvent Event = MessageEvent::Invalid;

		const MessageSource Source = MessageSource::None;

		// 光标事件信息
		const MouseButton MouseButton = MouseButton::None;

		const int CursorPositionX = 0;

		const int CursorPositionY = 0;

		// 键盘事件信息
		const KeyCode Key = KeyCode::Invalid;

	public:
		Message() = default;

		Message(const Message& other) = default;

		// 构建鼠标消息
		Message(MessageEvent ev, g2d::MouseButton btn, uint32_t x, uint32_t y);

		// 构建键盘消息
		Message(MessageEvent ev, KeyCode key);

		// 构建LostFocus消息
		Message(MessageEvent ev, MessageSource src);

	public:
		// 以下接口有点二，供内部使用
		// 构建根据鼠标信息Message
		Message(MessageEvent ev, g2d::MouseButton btn);

		Message(const Message& m, int x, int y);

		// 根据键盘信息构建Message
		Message(const Message& m, KeyCode key);
	};

	G2DAPI Message TranslateMessageWin32(uint32_t message, uint32_t wparam, uint32_t lparam);
}