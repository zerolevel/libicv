/*            I C V _ I M A G E _ R G B 2 G R A Y . C
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
/** @file icv_image_rgb2gray.c
 *
 * This File tests rgb2gray functionality of libicv.
 *
 */
#include "common.h"

#include "bio.h"

#include "bu.h"
#include "icv.h"

#define OUT_IMAGE "test_rgb2gray.pix"

int
main()
{
    char in_filename[120];
    int width, height;
    icv_image_t *bif;
    printf("Input bw file Name\n");
    if (scanf("%s", in_filename ) != 1) {
	bu_exit(1,"Wrong Arguments");
    }

    printf("input the width height of the Image file : ");
    if (scanf("%d %d", &width, &height)!=2)
	bu_exit(1,"Wrong Arguments");

    if(!(bif = icv_image_load(in_filename, ICV_IMAGE_AUTO, width, height)))
	bu_exit(-1, "cannot open file\n");

    printf("...\nImage Loaded Successfully\n...\n");

    if (bif->color_space == ICV_COLOR_SPACE_GRAY) {
	printf("...\n Converting Image to RGB format\n...\n");
	icv_image_gray2rgb(bif);
	printf("...\n Converted Successfully\n...\n");
	pix_save(bif, OUT_IMAGE);
    }
    else {
	bu_log("Input image is not Gray Space Image");
	icv_image_free(bif);
    }

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
