/*
 *
 *  BlueZ - Bluetooth protocol stack for Linux
 *
 *  Copyright (C) 2004-2006  Marcel Holtmann <marcel@holtmann.org>
 *
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <errno.h>

#include <dbus/dbus.h>

#include "hcid.h"
#include "dbus.h"

DBusHandlerResult error_failed(DBusConnection *conn, DBusMessage *msg, int err)
{
	const char *str = strerror(err);

	return send_reply_and_unref(conn,
		dbus_message_new_error(msg, ERROR_INTERFACE ".Failed", str));
}

DBusHandlerResult error_invalid_arguments(DBusConnection *conn, DBusMessage *msg)
{
	return send_reply_and_unref(conn,
		dbus_message_new_error(msg, ERROR_INTERFACE ".InvalidArguments",
							"Invalid arguments"));
}

DBusHandlerResult error_not_implemented(DBusConnection *conn, DBusMessage *msg)
{
	return send_reply_and_unref(conn,
		dbus_message_new_error(msg, ERROR_INTERFACE ".NotImplemented",
							"Not implemented"));
}

DBusHandlerResult error_not_authorized(DBusConnection *conn, DBusMessage *msg)
{
	return send_reply_and_unref(conn,
		dbus_message_new_error(msg, ERROR_INTERFACE ".NotAuthorized",
							"Not authorized"));
}

DBusHandlerResult error_out_of_memory(DBusConnection *conn, DBusMessage *msg)
{
	return send_reply_and_unref(conn,
		dbus_message_new_error(msg, ERROR_INTERFACE ".OutOfMemory",
							"Out of memory"));
}

DBusHandlerResult error_no_such_adapter(DBusConnection *conn, DBusMessage *msg)
{
	return send_reply_and_unref(conn,
		dbus_message_new_error(msg, ERROR_INTERFACE ".NoSuchAdapter",
							"No such adapter"));
}

DBusHandlerResult error_unknown_address(DBusConnection *conn, DBusMessage *msg)
{
	return send_reply_and_unref(conn,
		dbus_message_new_error(msg, ERROR_INTERFACE ".UnknownAddress",
							"Unknown address"));
}

DBusHandlerResult error_not_available(DBusConnection *conn, DBusMessage *msg)
{
	return send_reply_and_unref(conn,
		dbus_message_new_error(msg, ERROR_INTERFACE ".NotAvailable",
							"Not available"));
}

DBusHandlerResult error_request_deferred(DBusConnection *conn, DBusMessage *msg)
{
	return send_reply_and_unref(conn,
		dbus_message_new_error(msg, ERROR_INTERFACE ".RequestDeferred",
							"Request Deferred"));
}

DBusHandlerResult error_not_connected(DBusConnection *conn, DBusMessage *msg)
{
	return send_reply_and_unref(conn,
		dbus_message_new_error(msg, ERROR_INTERFACE ".NotConnected",
							"Not connected"));
}

DBusHandlerResult error_unsupported_major_class(DBusConnection *conn, DBusMessage *msg)
{
	return send_reply_and_unref(conn,
		dbus_message_new_error(msg, ERROR_INTERFACE ".UnsupportedMajorClass",
							"Unsupported Major Class"));
}

DBusHandlerResult error_connection_attempt_failed(DBusConnection *conn, DBusMessage *msg, int err)
{
	return send_reply_and_unref(conn,
		dbus_message_new_error(msg, ERROR_INTERFACE ".ConnectionAttemptFailed",
					err ? strerror(err) : "Connection attempt failed"));
}

static DBusHandlerResult error_already_exists(DBusConnection *conn, DBusMessage *msg, const char *str)
{
	return send_reply_and_unref(conn,
		dbus_message_new_error(msg, ERROR_INTERFACE ".AlreadyExists", str));
}

static DBusHandlerResult error_does_not_exist(DBusConnection *conn, DBusMessage *msg, const char *str)
{
	return send_reply_and_unref(conn,
		dbus_message_new_error(msg, ERROR_INTERFACE ".DoesNotExist", str));
}

static DBusHandlerResult error_in_progress(DBusConnection *conn, DBusMessage *msg, const char *str)
{
	return send_reply_and_unref(conn,
		dbus_message_new_error(msg, ERROR_INTERFACE ".InProgress", str));
}

static DBusHandlerResult error_not_in_progress(DBusConnection *conn, DBusMessage *msg, const char *str)
{
	return send_reply_and_unref(conn,
		dbus_message_new_error(msg, ERROR_INTERFACE ".NotInProgress", str));
}

static DBusHandlerResult error_canceled(DBusConnection *conn, DBusMessage *msg, const char *str)
{
	return send_reply_and_unref(conn,
		dbus_message_new_error(msg, ERROR_INTERFACE ".Canceled", str));
}

DBusHandlerResult error_connect_canceled(DBusConnection *conn, DBusMessage *msg)
{
	return error_canceled(conn, msg, "Connection creation was canceled");
}

DBusHandlerResult error_bonding_already_exists(DBusConnection *conn, DBusMessage *msg)
{
	return error_already_exists(conn, msg, "Bonding already exists");
}

DBusHandlerResult error_bonding_does_not_exist(DBusConnection *conn, DBusMessage *msg)
{
	return error_does_not_exist(conn, msg, "Bonding does not exist");
}

DBusHandlerResult error_bonding_in_progress(DBusConnection *conn, DBusMessage *msg)
{
	return error_in_progress(conn, msg, "Bonding in progress");
}

DBusHandlerResult error_discover_in_progress(DBusConnection *conn, DBusMessage *msg)
{
	return error_in_progress(conn, msg, "Discover in progress");
}

DBusHandlerResult error_connect_in_progress(DBusConnection *conn, DBusMessage *msg)
{
	return error_in_progress(conn, msg, "Connection creation in progress");
}

DBusHandlerResult error_connect_not_in_progress(DBusConnection *conn, DBusMessage *msg)
{
	return error_not_in_progress(conn, msg, "Connection creation not in progress");
}

DBusHandlerResult error_record_does_not_exist(DBusConnection *conn, DBusMessage *msg)
{
	return error_does_not_exist(conn, msg, "Record does not exist");
}

DBusHandlerResult error_passkey_agent_already_exists(DBusConnection *conn, DBusMessage *msg)
{
	return error_already_exists(conn, msg, "Passkey agent already exists");
}

DBusHandlerResult error_passkey_agent_does_not_exist(DBusConnection *conn, DBusMessage *msg)
{
	return error_does_not_exist(conn, msg, "Passkey agent does not exist");
}

DBusHandlerResult error_binding_does_not_exist(DBusConnection *conn, DBusMessage *msg)
{
	return error_does_not_exist(conn, msg, "Binding does not exist");
}
