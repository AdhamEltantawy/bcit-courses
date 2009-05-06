/*
 * spry.h
 * Copyright (C) 2009 Doug Penner <darwinsurvivor@gmail.com>
 *                    Brendan Neva <bneva1@my.bcit.ca>
 *                    Steffen L. Norgren <ironix@trollop.org>
 *                    Eddie Zhang <edisonhammer@gmail.com>
 * 
 * cliopts.h is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * spry.h is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _SPRY_H_
#define _SPRY_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <webkit/webkit.h>


/**
 * SPRY_CONF:
 * @init_url: initial url #char*
 * @fullscreen: fullscreen mode enabled #int
 * @context_menu: context menu enabled #int
 * @scrollbars: scrollbars enabled #int
 * @has_past: whether there is a previous URL #int
 * @has_future: whether there is a next URL #int
 * @window_size: the size of the browser window #int[2]
 *
 * This holds all command-line option settings as well as general configuration
 */


/* browser statuses */
#define HAS_PAST    0x1
#define HAS_FUTURE  0x2

/* modes */
#define FULLSCREEN  0x1
#define TOOLBAR     0x2
#define CONTEXT     0x4

/* features_enabled */
#define FULLSCREEN_ENABLED      0x1
#define SCROLLBARS_ENABLED      0x2
#define CONTEXT_MENU_ENABLED    0x4

/* Holds main gtk objects used in the window */
typedef struct _spry_gtk_objects {
    GtkWidget*      main_window;
    GtkWidget*      v_box;
    GtkWidget*      toolbar;
    GtkWidget*      toolbar_fullscreen;
    GtkWidget*      context_menu;
    GtkWidget*      scrolled_window;
    WebKitWebView*  web_view;
    
} SPRY_GTK_OBJECTS, *pSPRY_GTK_OBJECTS;

/* Spry browser configuration */
typedef struct _spry_conf { /* This is the old version, see below */
	char	*init_url;
	int		fullscreen,
			context_menu,
			scrollbars,
			resizable,
			has_past,
			has_future;
	int		window_size[2];
    SPRY_GTK_OBJECTS* gtk_objects;
} SPRY_CONF, *pSPRY_CONF;

/*
 * This should replace the above struct
typedef struct _spry_conf {
	char	*init_url;
	int		mode,
            features,
            browser_status,
	int		window_size[2];
    SPRY_GTK_OBJECTS* gtk_objects;
} SPRY_CONF, *pSPRY_CONF;
*/

#endif
