/*              I C V _ C R E A T E _ I M A G E . C
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
/** @file icv_create_image.c
 *
 * This program tests icv_image_create function and saves the input into the bw/pix file.
 *
 */

#include "common.h"

#include <stdio.h>
#include <stdlib.h>

#include "bu.h"
#include "icv.h"

int main()
{
    int width, height, options;
    icv_image_t * bif;
    char *filename;
    ICV_IMAGE_FORMAT format;

    bu_log("input the width height of the Image file : ");
    if(scanf("%d %d", &width, &height)!=2)
	bu_exit(1,"Wrong Arguments");

    printf("Options\n, \
	   \t 1. For Black and white\n \
	   \t 2. For Pix Image\n");

    if(scanf("%d", &options)!=1)
	bu_exit(1,"Wrong Arguments");

    switch (options) {
	case 1:
	    bif = icv_image_create(width, height, ICV_COLOR_SPACE_GRAY);
	    filename = "test.bw";
	    format = ICV_IMAGE_BW;
	break;
	case 2:
	    bif = icv_image_create(width, height, ICV_COLOR_SPACE_RGB);
	    filename = "test.pix";
	    format = ICV_IMAGE_PIX;
	break;
	default :
	    printf("\nWrong Options");
	    exit(1);
	break;
    }

    printf("\n...\nThis test function is saving the image\n...\n Filename : %s\n", filename );

    icv_image_save(bif, filename, format);

    icv_image_free(bif);

    return 0;
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
