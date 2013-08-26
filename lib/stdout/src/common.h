/*
 * OLSRd stdout plugin common header file
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation or - at your option - under
 * the terms of the GNU General Public Licence version 2 but can be
 * linked to any BSD-Licenced Software with public available sourcecode
 *
 */

int olsrd_plugin_interface_version(void);

void olsrd_get_plugin_parameters(const struct olsrd_plugin_parameters **,int *);

int olsrd_plugin_init(void);

void stdout_init(void);

void stdout_fini(void);

int stdout_addroute(const struct rt_entry *);

int stdout_delroute(const struct rt_entry *);
