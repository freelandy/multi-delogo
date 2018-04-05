/*
 * Copyright (C) 2018 Werner Turing <werner.turing@protonmail.com>
 *
 * This file is part of multi-delogo.
 *
 * multi-delogo is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * multi-delogo is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with multi-delogo.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MDL_UNDO_MANAGER_H
#define MDL_UNDO_MANAGER_H

#include <deque>

#include "EditAction.hpp"


namespace mdl {
  class Coordinator;


  class UndoManager
  {
  public:
    UndoManager(Coordinator& coordinator);

    void execute_action(edit_action_ptr action);

  private:
    std::deque<edit_action_ptr> undo_list_;
    std::deque<edit_action_ptr> redo_list_;

    Coordinator& coordinator_;


    void add_to_undo_list(edit_action_ptr action);
    void clear_redo_list();
  };
}

#endif // MDL_UNDO_MANAGER_H
