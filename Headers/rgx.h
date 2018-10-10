/*
 * BRLTTY - A background process providing access to the console screen (when in
 *          text mode) for a blind person using a refreshable braille display.
 *
 * Copyright (C) 1995-2018 by The BRLTTY Developers.
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

#ifndef BRLTTY_INCLUDED_RGX
#define BRLTTY_INCLUDED_RGX

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef struct RGX_ObjectStruct RGX_Object;
typedef struct RGX_PatternStruct RGX_Pattern;

extern RGX_Object *rgxNewObject (void *data);
extern void rgxDestroyObject (RGX_Object *rgx);

typedef struct {
  struct {
    const wchar_t *characters;
    size_t length;
  } pattern;

  struct {
    void *internal;
    const wchar_t *characters;
    size_t length;
  } text;

  struct {
    void *internal;
    size_t count;
  } captures;

  struct {
    void *object;
    void *pattern;
    void *match;
  } data;
} RGX_Match;

#define RGX_MATCH_HANDLER(name) void name (const RGX_Match *match)
typedef RGX_MATCH_HANDLER(RGX_MatchHandler);

extern RGX_Pattern *rgxAddPatternCharacters (
  RGX_Object *rgx,
  const wchar_t *characters, size_t length,
  RGX_MatchHandler *handler, void *data
);

extern RGX_Pattern *rgxAddPatternString (
  RGX_Object *rgx,
  const wchar_t *string,
  RGX_MatchHandler *handler, void *data
);

extern RGX_Pattern *rgxAddPatternUTF8 (
  RGX_Object *rgx,
  const char *string,
  RGX_MatchHandler *handler, void *data
);

extern int rgxMatchTextCharacters (
  RGX_Object *rgx,
  const wchar_t *characters, size_t length,
  void *data
);

extern int rgxMatchTextString (
  RGX_Object *rgx,
  const wchar_t *string,
  void *data
);

extern int rgxMatchTextUTF8 (
  RGX_Object *rgx,
  const char *string,
  void *data
);

extern size_t rgxGetCaptureCount (
  const RGX_Match *match
);

extern int rgxGetCaptureBounds (
  const RGX_Match *match,
  unsigned int index, int *from, int *to
);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* BRLTTY_INCLUDED_RGX */
