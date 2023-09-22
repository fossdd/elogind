/* SPDX-License-Identifier: LGPL-2.1-or-later */

#include "varlink-io.elogind.ManagedOOM.h"

/* Pull in vl_type_ControlGroup, since both interfaces need it */
#include "varlink-io.elogind.oom.h"

/* This is PID1's Varlink service, where PID 1 is the server and oomd is the client.
 *
 * Compare with io.elogind.oom where the client/server roles of oomd and the service manager are swapped! */

static VARLINK_DEFINE_METHOD(
                SubscribeManagedOOMCGroups,
                VARLINK_DEFINE_OUTPUT_BY_TYPE(cgroups, ControlGroup, VARLINK_ARRAY));

VARLINK_DEFINE_INTERFACE(
                io_elogind_ManagedOOM,
                "io.elogind.ManagedOOM",
                &vl_method_SubscribeManagedOOMCGroups,
                &vl_type_ControlGroup);
