#include <string>

#include "NumericEntry.hpp"

using namespace mdl;


NumericEntry::NumericEntry()
{
}


void NumericEntry::set_value(int text)
{
  set_text(std::to_string(text));
}


int NumericEntry::get_value() const
{
  return std::stoi(get_text());
}


void NumericEntry::on_insert_text(const Glib::ustring& text, int* position)
{
  if (contains_only_numbers(text)) {
    Gtk::Entry::on_insert_text(text, position);
  }
}


bool NumericEntry::contains_only_numbers(const Glib::ustring& text) const
{
  for (auto ch = text.begin(); ch != text.end(); ++ch) {
    if (*ch < '0' || *ch > '9') {
      return false;
    }
  }

  return true;
}
