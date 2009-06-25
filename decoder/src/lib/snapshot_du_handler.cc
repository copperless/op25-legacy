/* -*- C++ -*- */

/*
 * Copyright 2008 Steve Glass
 * 
 * This file is part of OP25.
 * 
 * OP25 is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * OP25 is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public
 * License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with OP25; see the file COPYING. If not, write to the Free
 * Software Foundation, Inc., 51 Franklin Street, Boston, MA
 * 02110-1301, USA.
 */

#include <snapshot_du_handler.h>
#include <string>

using std::string;

snapshot_du_handler::snapshot_du_handler(data_unit_handler_sptr next, gr_msg_queue_sptr msgq) :
   data_unit_handler(next),
   d_data_units(0),
   d_msgq(msgq)
{
}

snapshot_du_handler::~snapshot_du_handler()
{
}

void
snapshot_du_handler::handle(data_unit_sptr du)
{
   if(d_msgq) {
      string snapshot(du->snapshot());
      if(snapshot.size() > 0) {
         const size_t snapshot_sz = snapshot.size() + 1;
         gr_message_sptr msg = gr_make_message(/*type*/0, /*arg1*/++d_data_units, /*arg2*/0, snapshot_sz);
         char *snapshot_data = reinterpret_cast<char*>(msg->msg());
         memcpy(snapshot_data, snapshot.c_str(), snapshot_sz);
         d_msgq->handle(msg);
      }
   }
   data_unit_handler::handle(du);
}
