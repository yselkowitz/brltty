/*
 * BRLTTY - A background process providing access to the console screen (when in
 *          text mode) for a blind person using a refreshable braille display.
 *
 * Copyright (C) 1995-2021 by The BRLTTY Developers.
 *
 * BRLTTY comes with ABSOLUTELY NO WARRANTY.
 *
 * This is free software, placed under the terms of the
 * GNU Lesser General Public License, as published by the Free Software
 * Foundation; either version 2.1 of the License, or (at your option) any
 * later version. Please see the file LICENSE-LGPL for details.
 *
 * Web Page: http://brltty.app/
 *
 * This software is maintained by Dave Mielke <dave@mielke.cc>.
 */

#include "prologue.h"

#include "hid_defs.h"
#include "hid_tables.h"

#define HID_ITEM_TYPE_ENTRY(name) HID_TABLE_ENTRY(HID_ITM, name)
HID_BEGIN_TABLE(ItemType)
  HID_ITEM_TYPE_ENTRY(UsagePage),
  HID_ITEM_TYPE_ENTRY(Usage),
  HID_ITEM_TYPE_ENTRY(LogicalMinimum),
  HID_ITEM_TYPE_ENTRY(UsageMinimum),
  HID_ITEM_TYPE_ENTRY(LogicalMaximum),
  HID_ITEM_TYPE_ENTRY(UsageMaximum),
  HID_ITEM_TYPE_ENTRY(PhysicalMinimum),
  HID_ITEM_TYPE_ENTRY(DesignatorIndex),
  HID_ITEM_TYPE_ENTRY(PhysicalMaximum),
  HID_ITEM_TYPE_ENTRY(DesignatorMinimum),
  HID_ITEM_TYPE_ENTRY(UnitExponent),
  HID_ITEM_TYPE_ENTRY(DesignatorMaximum),
  HID_ITEM_TYPE_ENTRY(Unit),
  HID_ITEM_TYPE_ENTRY(ReportSize),
  HID_ITEM_TYPE_ENTRY(StringIndex),
  HID_ITEM_TYPE_ENTRY(Input),
  HID_ITEM_TYPE_ENTRY(ReportID),
  HID_ITEM_TYPE_ENTRY(StringMinimum),
  HID_ITEM_TYPE_ENTRY(Output),
  HID_ITEM_TYPE_ENTRY(ReportCount),
  HID_ITEM_TYPE_ENTRY(StringMaximum),
  HID_ITEM_TYPE_ENTRY(Collection),
  HID_ITEM_TYPE_ENTRY(Push),
  HID_ITEM_TYPE_ENTRY(Delimiter),
  HID_ITEM_TYPE_ENTRY(Feature),
  HID_ITEM_TYPE_ENTRY(Pop),
  HID_ITEM_TYPE_ENTRY(EndCollection),
HID_END_TABLE(ItemType)

#define HID_COLLECTION_TYPE_ENTRY(name) HID_TABLE_ENTRY(HID_COL, name)
HID_BEGIN_TABLE(CollectionType)
  HID_COLLECTION_TYPE_ENTRY(Physical),
  HID_COLLECTION_TYPE_ENTRY(Application),
  HID_COLLECTION_TYPE_ENTRY(Logical),
HID_END_TABLE(CollectionType)

#define HID_USAGE_TYPE_ENTRY(name) HID_TABLE_ENTRY(HID_USG_TYPE, name)
HID_BEGIN_TABLE(UsageType)
  HID_USAGE_TYPE_ENTRY(LC),
  HID_USAGE_TYPE_ENTRY(OOC),
  HID_USAGE_TYPE_ENTRY(MC),
  HID_USAGE_TYPE_ENTRY(OSC),
  HID_USAGE_TYPE_ENTRY(RTC),
  HID_USAGE_TYPE_ENTRY(SEL),
  HID_USAGE_TYPE_ENTRY(SV),
  HID_USAGE_TYPE_ENTRY(SF),
  HID_USAGE_TYPE_ENTRY(DV),
  HID_USAGE_TYPE_ENTRY(DF),
  HID_USAGE_TYPE_ENTRY(NARY),
  HID_USAGE_TYPE_ENTRY(CA),
  HID_USAGE_TYPE_ENTRY(CL),
  HID_USAGE_TYPE_ENTRY(CP),
  HID_USAGE_TYPE_ENTRY(US),
  HID_USAGE_TYPE_ENTRY(UM),
HID_END_TABLE(UsageType)

#define HID_USAGE_ENTRY(prefix, name, type) HID_TABLE_ENTRY(prefix, name, .usageType=HID_USG_TYPE_##type)

#define HID_GENERIC_DESKTOP_USAGE_ENTRY(name, type) HID_USAGE_ENTRY(HID_USG_GDT, name, type)
HID_BEGIN_TABLE(GenericDesktopUsage)
  HID_GENERIC_DESKTOP_USAGE_ENTRY(Pointer, CP),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(Mouse, CA),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(Joystick, CA),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(GamePad, CA),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(Keyboard, CA),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(Keypad, CA),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(MultiAxisController, CA),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(TabletPCSystemControls, CA),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(X, DV),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(Y, DV),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(Z, DV),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(Rx, DV),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(Ry, DV),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(Rz, DV),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(Slider, DV),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(Dial, DV),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(Wheel, DV),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(HatSwitch, DV),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(CountedBuffer, CL),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(ByteCount, DV),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(MotionWakeup, OSC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(Start, OOC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(Select, OOC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(Vx, DV),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(Vy, DV),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(Vz, DV),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(Vbrx, DV),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(Vbry, DV),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(Vbrz, DV),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(Vno, DV),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(FeatureNotification, DV),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(ResolutionMultiplier, DV),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemControl, CA),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemPowerDown, OSC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemSleep, OSC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemWakeUp, OSC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemContextMenu, OSC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemMainMenu, OSC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemAppMenu, OSC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemMenuHelp, OSC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemMenuExit, OSC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemMenuSelect, OSC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemMenuRight, RTC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemMenuLeft, RTC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemMenuUp, RTC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemMenuDown, RTC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemColdRestart, OSC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemWarmRestart, OSC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(DPadUp, OOC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(DPadDown, OOC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(DPadRight, OOC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(DPadLeft, OOC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemDock, OSC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemUndock, OSC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemSetup, OSC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemBreak, OSC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemDebuggerBreak, OSC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(ApplicationBreak, OSC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(ApplicationDebuggerBreak, OSC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemSpeakerMute, OSC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemHibernate, OSC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemDisplayInvert, OSC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemDisplayInternal, OSC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemDisplayExternal, OSC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemDisplayBoth, OSC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemDisplayDual, OSC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemDisplayToggleIntExt, OSC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemDisplaySwap, OSC),
  HID_GENERIC_DESKTOP_USAGE_ENTRY(SystemDisplayLCDAutoscale, OSC),
HID_END_TABLE(GenericDesktopUsage)

#define HID_KEYBOARD_USAGE_ENTRY(name, type) HID_USAGE_ENTRY(HID_USG_KBD, name, type)
HID_BEGIN_TABLE(KeyboardUsage)
  HID_KEYBOARD_USAGE_ENTRY(KeyboardErrorRollOver, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardPostFail, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardErrorUndefined, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardA, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardB, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardC, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardD, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardE, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardF, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardG, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardH, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardI, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardJ, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardK, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardL, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardM, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardN, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardO, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardP, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardQ, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardR, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardS, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardT, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardU, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardV, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardW, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardX, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardY, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardZ, SEL),
  HID_KEYBOARD_USAGE_ENTRY(Keyboard1, SEL),
  HID_KEYBOARD_USAGE_ENTRY(Keyboard2, SEL),
  HID_KEYBOARD_USAGE_ENTRY(Keyboard3, SEL),
  HID_KEYBOARD_USAGE_ENTRY(Keyboard4, SEL),
  HID_KEYBOARD_USAGE_ENTRY(Keyboard5, SEL),
  HID_KEYBOARD_USAGE_ENTRY(Keyboard6, SEL),
  HID_KEYBOARD_USAGE_ENTRY(Keyboard7, SEL),
  HID_KEYBOARD_USAGE_ENTRY(Keyboard8, SEL),
  HID_KEYBOARD_USAGE_ENTRY(Keyboard9, SEL),
  HID_KEYBOARD_USAGE_ENTRY(Keyboard0, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardEnter, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardEscape, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardBackspace, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardTab, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardSpace, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardMinus, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardEqual, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardLeftBracket, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardRightBracket, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardBackslash, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardEurope1, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardSemicolon, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardApostrophe, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardGrave, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardComma, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardPeriod, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardSlash, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardCapsLock, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardF1, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardF2, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardF3, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardF4, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardF5, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardF6, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardF7, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardF8, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardF9, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardF10, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardF11, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardF12, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardPrintScreen, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardScrollLock, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardPause, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardInsert, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardHome, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardPageUp, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardDelete, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardEnd, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardPageDown, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardRightArrow, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardLeftArrow, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardDownArrow, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardUpArrow, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadNumLock, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadSlash, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadAsterisk, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadMinus, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadPlus, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadEnter, SEL),
  HID_KEYBOARD_USAGE_ENTRY(Keypad1, SEL),
  HID_KEYBOARD_USAGE_ENTRY(Keypad2, SEL),
  HID_KEYBOARD_USAGE_ENTRY(Keypad3, SEL),
  HID_KEYBOARD_USAGE_ENTRY(Keypad4, SEL),
  HID_KEYBOARD_USAGE_ENTRY(Keypad5, SEL),
  HID_KEYBOARD_USAGE_ENTRY(Keypad6, SEL),
  HID_KEYBOARD_USAGE_ENTRY(Keypad7, SEL),
  HID_KEYBOARD_USAGE_ENTRY(Keypad8, SEL),
  HID_KEYBOARD_USAGE_ENTRY(Keypad9, SEL),
  HID_KEYBOARD_USAGE_ENTRY(Keypad0, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadPeriod, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardEurope2, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardApplication, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardPower, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadEqual, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardF13, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardF14, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardF15, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardF16, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardF17, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardF18, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardF19, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardF20, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardF21, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardF22, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardF23, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardF24, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardExecute, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardHelp, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardMenu, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardSelect, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardStop, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardAgain, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardUndo, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardCut, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardCopy, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardPaste, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardFind, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardMute, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardVolumeUp, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardVolumeDown, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardLockingCapsLock, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardLockingNumLock, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardLockingScrollLock, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadComma, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadEqualSign, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardInternational1, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardInternational2, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardInternational3, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardInternational4, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardInternational5, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardInternational6, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardInternational7, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardInternational8, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardInternational9, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardLanguage1, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardLanguage2, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardLanguage3, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardLanguage4, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardLanguage5, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardLanguage6, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardLanguage7, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardLanguage8, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardLanguage9, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardAlternateErase, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardSystemRequest, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardCancel, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardClear, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardPrior, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardReturn, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardSeparator, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardOut, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardOper, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardClearAgain, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardCrSel, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardExSel, SEL),
  HID_KEYBOARD_USAGE_ENTRY(Keypad00, SEL),
  HID_KEYBOARD_USAGE_ENTRY(Keypad000, SEL),
  HID_KEYBOARD_USAGE_ENTRY(ThousandsSeparator, SEL),
  HID_KEYBOARD_USAGE_ENTRY(DecimalSeparator, SEL),
  HID_KEYBOARD_USAGE_ENTRY(CurrencyUnit, SEL),
  HID_KEYBOARD_USAGE_ENTRY(CurrencySubunit, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadLeftParenthesis, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadRightParenthesis, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadLeftBrace, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadRightBrace, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadTab, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadBackspace, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadA, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadB, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadC, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadD, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadE, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadF, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadBitwiseXOR, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadExponentiate, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadModulo, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadLess, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadGreater, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadBitwiseAND, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadBooleanAND, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadBitwiseOR, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadBooleanOR, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadColon, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadNumber, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadSpace, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadAt, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadBoleanNOT, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadMemoryStore, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadMemoryRecall, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadMemoryClear, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadMemoryAdd, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadMemorySubtract, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadMemoryMultiply, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadMemoryDivide, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadPlusMinus, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadClear, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadClearEntry, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadBinary, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadOctal, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadDecimal, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeypadHexadecimal, SEL),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardLeftControl, DF),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardLeftShift, DF),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardLeftAlt, DF),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardLeftGUI, DF),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardRightControl, DF),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardRightShift, DF),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardRightAlt, DF),
  HID_KEYBOARD_USAGE_ENTRY(KeyboardRightGUI, DF),
HID_END_TABLE(KeyboardUsage)

#define HID_LEDS_USAGE_ENTRY(name, type) HID_USAGE_ENTRY(HID_USG_LED, name, type)
HID_BEGIN_TABLE(LEDsUsage)
  HID_LEDS_USAGE_ENTRY(NumLock, OOC),
  HID_LEDS_USAGE_ENTRY(CapsLock, OOC),
  HID_LEDS_USAGE_ENTRY(ScrollLock, OOC),
  HID_LEDS_USAGE_ENTRY(Compose, OOC),
  HID_LEDS_USAGE_ENTRY(Kana, OOC),
  HID_LEDS_USAGE_ENTRY(Power, OOC),
  HID_LEDS_USAGE_ENTRY(Shift, OOC),
  HID_LEDS_USAGE_ENTRY(DoNotDisturb, OOC),
  HID_LEDS_USAGE_ENTRY(Mute, OOC),
  HID_LEDS_USAGE_ENTRY(ToneEnable, OOC),
  HID_LEDS_USAGE_ENTRY(HighCutFilter, OOC),
  HID_LEDS_USAGE_ENTRY(LowCutFilter, OOC),
  HID_LEDS_USAGE_ENTRY(EqualizerEnable, OOC),
  HID_LEDS_USAGE_ENTRY(SoundFieldOn, OOC),
  HID_LEDS_USAGE_ENTRY(SurroundOn, OOC),
  HID_LEDS_USAGE_ENTRY(Repeat, OOC),
  HID_LEDS_USAGE_ENTRY(Stereo, OOC),
  HID_LEDS_USAGE_ENTRY(SamplingRateDetect, OOC),
  HID_LEDS_USAGE_ENTRY(Spinning, OOC),
  HID_LEDS_USAGE_ENTRY(CAV, OOC),
  HID_LEDS_USAGE_ENTRY(CLV, OOC),
  HID_LEDS_USAGE_ENTRY(RecordingFormatDetect, OOC),
  HID_LEDS_USAGE_ENTRY(OffHook, OOC),
  HID_LEDS_USAGE_ENTRY(Ring, OOC),
  HID_LEDS_USAGE_ENTRY(MessageWaiting, OOC),
  HID_LEDS_USAGE_ENTRY(DataMode, OOC),
  HID_LEDS_USAGE_ENTRY(BatteryOperation, OOC),
  HID_LEDS_USAGE_ENTRY(BatteryOK, OOC),
  HID_LEDS_USAGE_ENTRY(BatteryLow, OOC),
  HID_LEDS_USAGE_ENTRY(Speaker, OOC),
  HID_LEDS_USAGE_ENTRY(HeadSet, OOC),
  HID_LEDS_USAGE_ENTRY(Hold, OOC),
  HID_LEDS_USAGE_ENTRY(Microphone, OOC),
  HID_LEDS_USAGE_ENTRY(Coverage, OOC),
  HID_LEDS_USAGE_ENTRY(NightMode, OOC),
  HID_LEDS_USAGE_ENTRY(SendCalls, OOC),
  HID_LEDS_USAGE_ENTRY(CallPickup, OOC),
  HID_LEDS_USAGE_ENTRY(Conference, OOC),
  HID_LEDS_USAGE_ENTRY(StandBy, OOC),
  HID_LEDS_USAGE_ENTRY(CameraOn, OOC),
  HID_LEDS_USAGE_ENTRY(CameraOff, OOC),
  HID_LEDS_USAGE_ENTRY(OnLine, OOC),
  HID_LEDS_USAGE_ENTRY(OffLine, OOC),
  HID_LEDS_USAGE_ENTRY(Busy, OOC),
  HID_LEDS_USAGE_ENTRY(Ready, OOC),
  HID_LEDS_USAGE_ENTRY(PaperOut, OOC),
  HID_LEDS_USAGE_ENTRY(PaperJam, OOC),
  HID_LEDS_USAGE_ENTRY(Remote, OOC),
  HID_LEDS_USAGE_ENTRY(Forward, OOC),
  HID_LEDS_USAGE_ENTRY(Reverse, OOC),
  HID_LEDS_USAGE_ENTRY(Stop, OOC),
  HID_LEDS_USAGE_ENTRY(Rewind, OOC),
  HID_LEDS_USAGE_ENTRY(FastForward, OOC),
  HID_LEDS_USAGE_ENTRY(Play, OOC),
  HID_LEDS_USAGE_ENTRY(Pause, OOC),
  HID_LEDS_USAGE_ENTRY(Record, OOC),
  HID_LEDS_USAGE_ENTRY(Error, OOC),
  HID_LEDS_USAGE_ENTRY(UsageSelectedIndicator, US),
  HID_LEDS_USAGE_ENTRY(UsageInUseIndicator, US),
  HID_LEDS_USAGE_ENTRY(UsageMultiModeIndicator, UM),
  HID_LEDS_USAGE_ENTRY(IndicatorOn, SEL),
  HID_LEDS_USAGE_ENTRY(IndicatorFlash, SEL),
  HID_LEDS_USAGE_ENTRY(IndicatorSlowBlink, SEL),
  HID_LEDS_USAGE_ENTRY(IndicatorFastBlink, SEL),
  HID_LEDS_USAGE_ENTRY(IndicatorOff, SEL),
  HID_LEDS_USAGE_ENTRY(FlashOnTime, DV),
  HID_LEDS_USAGE_ENTRY(SlowBlinkOnTime, DV),
  HID_LEDS_USAGE_ENTRY(SlowBlinkOffTime, DV),
  HID_LEDS_USAGE_ENTRY(FastBlinkOnTime, DV),
  HID_LEDS_USAGE_ENTRY(FastBlinkOffTime, DV),
  HID_LEDS_USAGE_ENTRY(UsageIndicatorColor, UM),
  HID_LEDS_USAGE_ENTRY(IndicatorRed, SEL),
  HID_LEDS_USAGE_ENTRY(IndicatorGreen, SEL),
  HID_LEDS_USAGE_ENTRY(IndicatorAmber, SEL),
  HID_LEDS_USAGE_ENTRY(GenericIndicator, OOC),
  HID_LEDS_USAGE_ENTRY(SystemSuspend, OOC),
  HID_LEDS_USAGE_ENTRY(ExternalPowerConnected, OOC),
HID_END_TABLE(LEDsUsage)

#define HID_BRAILLE_USAGE_ENTRY(name, type) HID_USAGE_ENTRY(HID_USG_BRL, name, type)
HID_BEGIN_TABLE(BrailleUsage)
  HID_BRAILLE_USAGE_ENTRY(BrailleDisplay, CA),
  HID_BRAILLE_USAGE_ENTRY(BrailleRow, NARY),
  HID_BRAILLE_USAGE_ENTRY(8DotCell, DV),
  HID_BRAILLE_USAGE_ENTRY(6DotCell, DV),
  HID_BRAILLE_USAGE_ENTRY(CellCount, DV),
  HID_BRAILLE_USAGE_ENTRY(ScreenReaderControl, NARY),
  HID_BRAILLE_USAGE_ENTRY(ScreenReaderIdentifier, DV),
  HID_BRAILLE_USAGE_ENTRY(RouterSet1, NARY),
  HID_BRAILLE_USAGE_ENTRY(RouterSet2, NARY),
  HID_BRAILLE_USAGE_ENTRY(RouterSet3, NARY),
  HID_BRAILLE_USAGE_ENTRY(RouterKey, SEL),
  HID_BRAILLE_USAGE_ENTRY(RowRouterKey, SEL),
  HID_BRAILLE_USAGE_ENTRY(BrailleButtons, NARY),
  HID_BRAILLE_USAGE_ENTRY(KeyboardDot1, SEL),
  HID_BRAILLE_USAGE_ENTRY(KeyboardDot2, SEL),
  HID_BRAILLE_USAGE_ENTRY(KeyboardDot3, SEL),
  HID_BRAILLE_USAGE_ENTRY(KeyboardDot4, SEL),
  HID_BRAILLE_USAGE_ENTRY(KeyboardDot5, SEL),
  HID_BRAILLE_USAGE_ENTRY(KeyboardDot6, SEL),
  HID_BRAILLE_USAGE_ENTRY(KeyboardDot7, SEL),
  HID_BRAILLE_USAGE_ENTRY(KeyboardDot8, SEL),
  HID_BRAILLE_USAGE_ENTRY(KeyboardSpace, SEL),
  HID_BRAILLE_USAGE_ENTRY(KeyboardLeftSpace, SEL),
  HID_BRAILLE_USAGE_ENTRY(KeyboardRightSpace, SEL),
  HID_BRAILLE_USAGE_ENTRY(FrontControls, NARY),
  HID_BRAILLE_USAGE_ENTRY(LeftControls, NARY),
  HID_BRAILLE_USAGE_ENTRY(RightControls, NARY),
  HID_BRAILLE_USAGE_ENTRY(TopControls, NARY),
  HID_BRAILLE_USAGE_ENTRY(JoystickCenter, SEL),
  HID_BRAILLE_USAGE_ENTRY(JoystickUp, SEL),
  HID_BRAILLE_USAGE_ENTRY(JoystickDown, SEL),
  HID_BRAILLE_USAGE_ENTRY(JoystickLeft, SEL),
  HID_BRAILLE_USAGE_ENTRY(JoystickRight, SEL),
  HID_BRAILLE_USAGE_ENTRY(DPadCenter, SEL),
  HID_BRAILLE_USAGE_ENTRY(DPadUp, SEL),
  HID_BRAILLE_USAGE_ENTRY(DPadDown, SEL),
  HID_BRAILLE_USAGE_ENTRY(DPadLeft, SEL),
  HID_BRAILLE_USAGE_ENTRY(DPadRight, SEL),
  HID_BRAILLE_USAGE_ENTRY(PanLeft, SEL),
  HID_BRAILLE_USAGE_ENTRY(PanRight, SEL),
  HID_BRAILLE_USAGE_ENTRY(RockerUp, SEL),
  HID_BRAILLE_USAGE_ENTRY(RockerDown, SEL),
  HID_BRAILLE_USAGE_ENTRY(RockerPress, SEL),
HID_END_TABLE(BrailleUsage)

#define HID_USAGE_PAGE_ENTRY(name, usages) HID_TABLE_ENTRY(HID_UPG, name, .usageTable=usages)
HID_BEGIN_TABLE(UsagePage)
  HID_USAGE_PAGE_ENTRY(GenericDesktop, &hidGenericDesktopUsageTable),
  HID_USAGE_PAGE_ENTRY(Simulation, NULL),
  HID_USAGE_PAGE_ENTRY(VirtualReality, NULL),
  HID_USAGE_PAGE_ENTRY(Sport, NULL),
  HID_USAGE_PAGE_ENTRY(Game, NULL),
  HID_USAGE_PAGE_ENTRY(GenericDevice, NULL),
  HID_USAGE_PAGE_ENTRY(Keyboard_Keypad, &hidKeyboardUsageTable),
  HID_USAGE_PAGE_ENTRY(LEDs, &hidLEDsUsageTable),
  HID_USAGE_PAGE_ENTRY(Button, NULL),
  HID_USAGE_PAGE_ENTRY(Ordinal, NULL),
  HID_USAGE_PAGE_ENTRY(Telephony, NULL),
  HID_USAGE_PAGE_ENTRY(Consumer, NULL),
  HID_USAGE_PAGE_ENTRY(Digitizer, NULL),
  HID_USAGE_PAGE_ENTRY(PhysicalInterfaceDevice, NULL),
  HID_USAGE_PAGE_ENTRY(Unicode, NULL),
  HID_USAGE_PAGE_ENTRY(AlphanumericDisplay, NULL),
  HID_USAGE_PAGE_ENTRY(MedicalInstruments, NULL),
  HID_USAGE_PAGE_ENTRY(BarCodeScanner, NULL),
  HID_USAGE_PAGE_ENTRY(Braille, &hidBrailleUsageTable),
  HID_USAGE_PAGE_ENTRY(Scale, NULL),
  HID_USAGE_PAGE_ENTRY(MagneticStripeReader, NULL),
  HID_USAGE_PAGE_ENTRY(Camera, NULL),
  HID_USAGE_PAGE_ENTRY(Arcade, NULL),
HID_END_TABLE(UsagePage)
