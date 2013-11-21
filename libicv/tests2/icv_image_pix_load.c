/*             I C V _ I M A G E _ B W _ L O A D . C
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
/** @file icv_image_bw_load.c
 *
 * this routine tests the load functionality of bw format.
 * it loads a bw image to icv_struct and saves the same image.
 *
 *  this also tests the save functionality.
 */

#include "common.h"

#include "bio.h"

#include "bu.h"
#include "icv.h"

#define OUT_IMAGE "test_icv_image_pix_load.pix"
int main()
{
    char in_filename[120];
    int width, height;
    icv_image_t *bif;
    printf("Input file Name\n");
    if (scanf("%s", in_filename ) != 1) {
	bu_exit(1,"Wrong Arguments");
    }

    printf("input the width height of the Image file : ");
    if(scanf("%d %d", &width, &height)!=2)
	bu_exit(1,"Wrong Arguments");


    bif = pix_load(in_filename, width, height);
    printf("...\nImage Loaded Successfully\n...\n");
    icv_image_save(bif, OUT_IMAGE, ICV_IMAGE_PIX);
    printf("...\nImage Saved Successfully\n...\n");
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
