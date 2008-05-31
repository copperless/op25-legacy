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

#ifndef INCLUDED_LDU1_H
#define INCLUDED_LDU1_H

#include <abstract_data_unit.h>

/*
 * P25 Logical Data Unit 1 (an IBME/AMBE voice frame).
 */
class ldu1 : public abstract_data_unit
{
public:
   ldu1(uint64_t frame_sync, uint64_t network_ID);
   virtual ~ldu1();
   virtual size_t nof_symbols_reqd() const;
};

#endif /* INCLUDED_LDU1_H */
