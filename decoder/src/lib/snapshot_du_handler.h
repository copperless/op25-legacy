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
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
 * License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with OP25; see the file COPYING.  If not, write to the Free
 * Software Foundation, Inc., 51 Franklin Street, Boston, MA
 * 02110-1301, USA.
*/

#ifndef INCLUDED_SNAPSHOT_DU_HANDLER_H
#define INCLUDED_SNAPSHOT_DU_HANDLER_H

#include <data_unit_handler.h>
#include <gr_msg_queue.h>
#include <boost/noncopyable.hpp>

/**
 * snapshot_du_handler. Writes traffic snapshots to a msg_queue based
 * on the HDU frame contents. The format used is that of a pickled
 * python dictionary allowing the other end of the queue to pick only
 * those fields of interest and ignore the rest.
 */
class snapshot_du_handler : public data_unit_handler
{

public:

   /**
    * snapshot_du_handler constructor.
    *
    * \param next The next data_unit_handler in the chain.
    * \param msgq A non-null msg_queue_sptr to the msg_queue to use.
    */
   snapshot_du_handler(data_unit_handler_sptr next, gr_msg_queue_sptr msgq);

   /**
    * snapshot_du_handler virtual destructor.
    */
   virtual ~snapshot_du_handler();

   /**
    * Handle a received P25 frame.
    *
    * \param du A non-null data_unit_sptr to handle.
    */
   virtual void handle(data_unit_sptr du);

private:

   /**
    * Count of the data units seen so far.
    */
   uint32_t d_data_units;

   /**
    * The msg_queue to which decoded frames are written.
    */
   gr_msg_queue_sptr d_msgq;

};

#endif /* INCLUDED_SNAPSHOT_DU_HANDLER_H */
