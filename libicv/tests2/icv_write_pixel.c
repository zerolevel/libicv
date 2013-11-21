/*          I C V _ W R I T E _ P I X E L _ L I N E . C
 * BRL-CAD
 *
 * Copyright (c) 2013 United States Government as represented by
 * the U.S. Army Research Laboratory.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * version 2.1 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this file; see the file named COPYING for more
 * information.
 */
/** @file icv_write_pixel.c
 *
 * This code tests write pixel functions in libicv.
 *
 * It creats a line of code. stores that in the image. reads the line
 * and checks if the line read are same as lines written
 *
 */

#include "common.h"

#include "icv.h"
#include "bu.h"
#include "vmath.h"

#include "bio.h"

#define SIZE 256

int
main()
{
    icv_image_t *bif;
    double line[SIZE];
    double *img_data;
    int i,j;

    bif = icv_image_create(SIZE, SIZE, ICV_COLOR_SPACE_GRAY);

    for (i = 0; i<SIZE; i++)
	line[i] = (double)i/SIZE;

    /* Writes the pixels from the line to the image */
    for (i = 0; i<SIZE; i++)
	for (j = 0; j<SIZE; j++)
	    icv_writepixel(bif, j, i, line+j);

    img_data = bif->data;

    for (i = 0; i<SIZE; i++)
	for (j = 0; j<SIZE; j++) {
	    if (!ZERO((*img_data - line[j]))) {
		bu_log("-----icv_writepixel failed-----\n");
		return 0;
	    }
	    img_data++;
	}

   bu_log("-----icv_writepixel test PASSED-----\n");

}

/*
 * Local Variables:
 * tab-width: 8
 * mode: C
 * indent-tabs-mode: t
 * c-file-style: "stroustrup"
 * End:
 * ex: shiftwidth=4 tabstop=8
 */
