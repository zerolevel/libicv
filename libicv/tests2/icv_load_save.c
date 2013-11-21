/*                 I C V _ L O A D _ W R I T E . C
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
/** @file icv_load_write.c
 *
 * This testing function is to test the time required in loading and
 * image to icv container and saving it again.
 *
 */

#include "icv.h"
#include "bu.h"

int main(int argc, char* argv[])
{
    int c;

    while ((c = bu_getopt(argc, argv, "s:w:n:o:h?")) != -1) {
	switch (c) {
	    case 'o':
		out_file = bu_optarg;
		break;
	    case 's' :
	       inx = iny = atoi(bu_optarg);
	       break;
	    case 'w' :
	       inx = atoi(bu_optarg);
	       break;
	    case 'n' :
	       iny = atoi(bu_optarg);
	       break;
	    case 'h':
	    default:		/* '?' */
		return 0;
	}
    }

    if (bu_optind >= argc) {
	if (isatty(fileno(stdin))) {
	    return 0;
	}
    } else {
	in_file = argv[bu_optind];
	bu_optind++;
	return 1;
    }


    if (!isatty(fileno(stdout)) && out_file!=NULL) {
	return 0;
    }

    if (argc > ++bu_optind) {
	bu_log("bw-pix: excess argument(s) ignored\n");
    }

    return 1;		/* OK */

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
