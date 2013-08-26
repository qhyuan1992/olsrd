/*
 * OLSRd stdout plugin
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation or - at your option - under
 * the terms of the GNU General Public Licence version 2 but can be
 * linked to any BSD-Licenced Software with public available sourcecode
 *
 */

#include "olsrd_plugin.h"
#include "scheduler.h"
#include "defs.h"
#include "process_routes.h"
#include "common.h"

#define PLUGIN_NAME    "OLSRD stdout routing plugin"
#define PLUGIN_VERSION "0.1"
#define PLUGIN_AUTHOR  "Will Hawkins"
#define MOD_DESC PLUGIN_NAME " " PLUGIN_VERSION " by " PLUGIN_AUTHOR
#define PLUGIN_INTERFACE_VERSION 5

static void __attribute__ ((constructor)) my_init(void);
static void __attribute__ ((destructor)) my_fini(void);

export_route_function original_add_route, original_del_route;

int
olsrd_plugin_interface_version(void)
{
  return PLUGIN_INTERFACE_VERSION;
}

void
olsrd_get_plugin_parameters(const struct olsrd_plugin_parameters **params, int *size)
{
  return;
}

int
olsrd_plugin_init(void)
{
  return 0;
}

static void
my_init(void)
{
  stdout_init();
}

static void
my_fini(void)
{
  stdout_fini();
}

void
stdout_init(void)
{
  original_add_route = olsr_addroute_function;
  original_del_route = olsr_delroute_function;
  olsr_addroute_function = stdout_addroute;
  olsr_delroute_function = stdout_delroute;
}

void
stdout_fini(void)
{
  olsr_addroute_function = original_add_route;
  olsr_delroute_function = original_del_route;
}

int stdout_print_command(const struct rt_entry *, const char *);
int
stdout_print_command(const struct rt_entry *r, const char *cmd)
{
  char gateway[INET_ADDRSTRLEN +1] = {'\0',};
  char prefix[INET_ADDRSTRLEN +1] = {'\0', };
  uint8_t prefix_len; 

  inet_ntop(AF_INET, &(r->rt_dst.prefix.v4), prefix, INET_ADDRSTRLEN);
  inet_ntop(AF_INET, &(r->rt_nexthop.gateway.v4), gateway, INET_ADDRSTRLEN);
  prefix_len = r->rt_dst.prefix_len;

  printf("%s %s %d %s\n", cmd, prefix, prefix_len, gateway);
  return 0;
}

int
stdout_addroute(const struct rt_entry *r)
{
  return stdout_print_command(r, "ADD");
}

int
stdout_delroute(const struct rt_entry *r)
{
  return stdout_print_command(r, "DEL");
}


