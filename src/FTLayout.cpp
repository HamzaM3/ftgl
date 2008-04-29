/*
 * FTGL - OpenGL font library
 *
 * Copyright (c) 2001-2004 Henry Maddocks <ftgl@opengl.geek.nz>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Alternatively, you can redistribute and/or modify this software under
 * the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License,
 * or (at your option) any later version.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this software; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA.
 */

#include "config.h"

#include "FTPoint.h"
#include "FTFont.h"
#include "FTFontImpl.h"

#include "FTLayout.h"
#include "FTLayoutImpl.h"

#include "FTSimpleLayoutImpl.h"


//
//  FTLayout
//


FTLayout::FTLayout(FTGL::LayoutType type)
{
    switch(type)
    {
        case FTGL::LAYOUT_SIMPLE:
            impl = new FTSimpleLayoutImpl();
            break;
    }
}


FTLayout::~FTLayout()
{
    delete impl;
}


void FTLayout::BBox(const char* string, float& llx, float& lly,
                    float& llz, float& urx, float& ury, float& urz)
{
    impl->BBox(string, llx, lly, llz, urx, ury, urz);
}

void FTLayout::BBox(const wchar_t* string, float& llx, float& lly,
                    float& llz, float& urx, float& ury, float& urz)
{
    impl->BBox(string, llx, lly, llz, urx, ury, urz);
}

void FTLayout::Render(const char *string)
{
    impl->Render(string);
}

void FTLayout::Render(const char *string, int renderMode)
{
    impl->Render(string, renderMode);
}

void FTLayout::Render(const wchar_t *string)
{
    impl->Render(string);
}

void FTLayout::Render(const wchar_t *string, int renderMode)
{
    impl->Render(string, renderMode);
}


//
//  FTLayoutImpl
//


void FTLayoutImpl::DoRender(FTFont *font, const unsigned int chr,
                            const unsigned int nextChr, int renderMode)
{
    font->impl->DoRender(chr, nextChr, pen, renderMode);
}


void FTLayoutImpl::CheckGlyph(FTFont *font, const unsigned int Chr)
{
    font->impl->CheckGlyph(Chr);
}


FTGlyphContainer * FTLayoutImpl::GetGlyphs(FTFont *font)
{
    return font->impl->glyphList;
}


FTSize & FTLayoutImpl::GetCharSize(FTFont *font)
{
    return font->impl->charSize;
}
