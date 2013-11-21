/*                    I C V _ F I L T E R . C
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
/** @file icv_filter.c
 *
 * Brief description
 *
 */

#include "common.h"

#include "bio.h"

#include "bu.h"
#include "icv.h"

#define OUT_IMAGE "test_icv_filter.bw"

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

    icv_filter(bif, ICV_FILTER_HIGH_PASS);

    pix_save(bif, OUT_IMAGE);
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
