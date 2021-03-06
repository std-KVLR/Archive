              in GETINFO opcode,
   *                                             Gray ClearType
   *   }
   *
   *   The `version' field gives a rough orientation only, since some
   *   applications provided certain features much earlier (as an example,
   *   Microsoft Reader used subpixel and Y-direction ClearType already in
   *   Windows 2000).  Similarly, updates to a given framework might include
   *   improved hinting support.
   *
   *   {
   *      version   sampling          rendering        comment
   *               x        y       x           y
   *     --------------------------------------------------------------
   *       v1.0   normal  normal  B/W           B/W    bi-level
   *       v1.6   high    high    gray          gray   grayscale
   *       v1.8   high    normal  color-filter  B/W    (GDI) ClearType
   *       v1.9   high    high    color-filter  gray   Color ClearType
   *       v2.1   high    normal  gray          B/W    Gray ClearType
   *       v2.1   high    high    gray          gray   Gray ClearType
   *   }
   *
   *   Color and Gray ClearType are the two available variants of
   *   `Y-direction ClearType', meaning grayscale rasterization along the
   *   Y-direction; the name used in the TrueType specification for this
   *   feature is `symmetric smoothing'.  `Classic ClearType' is the
   *   original algorithm used before introducing a modified version in
   *   Win~XP.  Another name for v1.6's grayscale rendering is `font
   *   smoothing', and `Color ClearType' is sometimes also called `DWrite
   *   ClearType'.  To differentiate between today's Color ClearType and the
   *   earlier ClearType variant with B/W rendering along the vertical axis,
   *   the latter is sometimes called `GDI ClearType'.
   *
   *   `Normal' and `high' sampling describe the (virtual) resolution to
   *   access the rasterized outline after the hinting process.  `Normal'
   *   means 1 sample per grid line (i.e., B/W).  In the current Microsoft
   *   implementation, `high' means an extra virtual resolution of 16x16 (or
   *   16x1) grid lines per pixel for bytecode instructions like `MIRP'.
   *   After hinting, these 16 grid lines are mapped to 6x5 (or 6x1) grid
   *   lines for color filtering if Color ClearType is activated.
   *
   *   Note that `Gray ClearType' is essentially the same as v1.6's
   *   grayscale rendering.  However, the GETINFO instruction handles it
   *   differently: v1.6 returns bit~12 (hinting for grayscale), while v2.1
   *   returns bits~13 (hinting for ClearType), 18 (symmetrical smoothing),
   *   and~19 (Gray ClearType).  Also, this mode respects bits 2 and~3 for
   *   the version~1 gasp table exclusively (like Color ClearType), while
   *   v1.6 only respects the values of version~0 (bits 0 and~1).
   *
   *   Keep in mind that the features of the above interpreter versions
   *   might not map exactly to FreeType features or behavior because it is
   *   a fundamentally different library with different internals.
   *
   */
#define TT_INTERPRETER_VERSION_35  35
#define TT_INTERPRETER_VERSION_38  38
#define TT_INTERPRETER_VERSION_40  40

 /* */


FT_END_HEADER


#endif /* FTTTDRV_H_ */


/* END */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        /***************************************************************************/
/*                                                                         */
/