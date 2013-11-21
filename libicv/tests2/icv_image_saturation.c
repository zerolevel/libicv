/*          I C V _ I M A G E _ S A T U R A T I O N . C
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
/** @file libicv/tests/icv_image_saturation.c
 *
 * this file tests functions for
 *
 */
#include "common.h"

#include "bio.h"

#include "bu.h"
#include "icv.h"

int
main()
{
    icv_image_t* bif;
    char in_filename[120];
    int width, height;
    printf("Input file Name\n");
    if (scanf("%s", in_filename ) != 1) {
	bu_exit(1,"Wrong Arguments");
    }

    printf("input the width height of the Image file : ");
    if(scanf("%d %d", &width, &height)!=2)
	bu_exit(1,"Wrong Arguments");

    bif = pix_load(in_filename,width, height);

    icv_saturate(bif, 0.8);

    pix_save(bif, "test_saturate.pix");

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
