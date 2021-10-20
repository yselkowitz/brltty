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

#ifndef BRLTTY_INCLUDED_HID_TYPES
#define BRLTTY_INCLUDED_HID_TYPES

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef uint32_t HidUnsignedValue;
typedef int32_t HidSignedValue;

typedef uint8_t HidReportIdentifier;
typedef uint16_t HidDeviceIdentifier;

typedef struct {
  size_t count;
  unsigned char bytes[];
} HidItemsDescriptor;

typedef struct {
  size_t input;
  size_t output;
  size_t feature;
} HidReportSize;

typedef struct {
  const char *manufacturerName;
  const char *productDescription;
  const char *serialNumber;
  HidDeviceIdentifier vendorIdentifier;
  HidDeviceIdentifier productIdentifier;
} HidUSBFilter;

typedef struct {
  const char *deviceAddress;
  const char *deviceName;
  HidDeviceIdentifier vendorIdentifier;
  HidDeviceIdentifier productIdentifier;
} HidBluetoothFilter;

typedef struct {
  struct {
    HidDeviceIdentifier vendor;
    HidDeviceIdentifier product;
  } identifiers;

  struct {
    const char *manufacturerName;
    const char *productDescription;
    const char *serialNumber;
  } usb;

  struct {
    const char *deviceAddress;
    const char *deviceName;
  } bluetooth;

  struct {
    unsigned char wantUSB:1;
    unsigned char wantBluetooth:1;
  } flags;
} HidFilter;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* BRLTTY_INCLUDED_HID_TYPES */
