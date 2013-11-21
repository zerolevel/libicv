/*                I C V _ I M A G E _ C R O P . C
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
/** @file icv_image_crop.c
 *
 * Brief description
 *
 */
#include "common.h"

#include "bio.h"

#include "bu.h"
#include "icv.h"

#define OUT_IMAGE "test_crop.pix"

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

    if(!(bif = icv_image_load(in_filename, ICV_IMAGE_BW, width, height)))
	bu_exit(-1, "cannot open file\n");

    bu_log("Loaded image successfully. Channels : %d, width : %d, height : %d\n", bif->channels, bif->width, bif->height);

    icv_crop(bif, 0, 250, 250 ,250, 250,0, 0, 0, 250, 250);

    bu_log("cropped image successfully. Channels : %d, width : %d, height : %d\n", bif->channels, bif->width, bif->height);

    icv_image_save(bif, OUT_IMAGE, ICV_IMAGE_PIX);
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
