_blob);
  }

  inline void fini (void)
  {
    hb_blob_destroy (this->blob);
    hb_blob_destroy (this->var_blob);
  }

  inline unsigned int get_advance (hb_codepoint_t  glyph,
				   hb_font_t      *font) const
  {
    if (unlikely (glyph >= this->num_metrics))
    {
      /* If this->num_metrics is zero, it means we don't have the metrics table
       * for this direction: return default advance.  Otherwise, it means that the
       * glyph index is out of bound: return zero. */
      if (this->num_metrics)
	return 0;
      else
	return this->default_advance;
    }

    return this->table->longMetric[MIN (glyph, this->num_advances - 1)].advance
	 + this->var->get_advance_var (glyph, font->coords, font->num_coords); // TODO Optimize?!
  }
};

struct hb_ot_face_glyf_accelerator_t
{
  bool short_offset;
  unsigned int num_glyphs;
  const OT::loca *loca;
  const OT::glyf *glyf;
  hb_blob_t *loca_blob;
  hb_blob_t *glyf_blob;
  unsigned int glyf_len;

  inline void init (hb_face_t *face)
  {
    hb_blob_t *head_blob = OT::Sanitizer<OT::head>::sanitize (face->reference_table (HB_OT_TAG_head));
    const OT::head *head = OT::Sanitizer<OT::head>::lock_instance (head_blob);
    if ((unsigned int) head->indexToLocFormat > 1 || head->glyphDataFormat != 0)
    {
      /* Unknown format.  Leave num_glyphs=0, that takes care of disabling us. */
      hb_blob_destroy (head_blob);
      return;
    }
    this->short_offset = 0 == head->indexToLocFormat;
    hb_blob_destroy (head_blob);

    this->loca_blob = OT::Sanitizer<OT::loca>::sanitize (face->refe