#ifndef COMBIN_H
#define COMBIN_H

#include <mib/algorithm.h>
#include <mib/pugi/operations.h>

using namespace mvc_utils::io;
using namespace mvc_utils::algorithm;
using namespace pugi;
using namespace pugi_operations;

namespace combined_impl
{
   using item_group = pugi::xml_node;

   class settings
   {
      public:
         settings();
         settings(cchar*);

         xml_node add_group(cchar*);
         xml_node add_group(cchar*, uint);

         item_group add_sub_group(xml_node&, cchar*);
         void add_sub_group(cchar*, cchar*);

         void load_file(cchar*);
         //bool save_file() { return save_file() }
         bool save_file(cchar* );

      private:
         xml_document doc = {};
         xml_node header = {};
   };

   settings::settings() : header(doc.append_child("Settings"))
   {
   }

   settings::settings(cchar* _fname)
   {
      doc.load_file(_fname);
      header = doc.child("Settings");
   }

   item_group settings::add_group(cchar* _grp_name, uint )
   {
      return append_child(header, _grp_name);
   }

   item_group settings::add_sub_group(item_group& _grp, cchar* _sub_group_name)
   {
      return append_child(_grp, _sub_group_name);
   }

   bool settings::save_file(cchar* _fname)
   {
      return doc.save_file(_fname);
   }

   void example()
   {
      xml_document doc;
      xml_node header;

      //doc.load_file("ss.xml");

      cchar* s = "Settings";
      auto pred = [&s](xml_node &nd) { return nd.name() != s; };

      if (!doc.find_child(pred))
         header = doc.append_child("Settings");

      xml_node sett_gui = append_child(header, "GUI"),
               sett_gui_wm = append_child(sett_gui, "MainWindow");

      xml_node sett_gui_size = append_child(sett_gui_wm, "size");
      append_attribute(sett_gui_size, "height", "400");
      append_attribute(sett_gui_size, "weight", "800");

      doc.save_file("ss.xml");
   }

   void example1() ///Reading
   {
      xml_document doc;
      doc.load_file("ss.xml");
      cchar* s = "size";
      cchar* mw = "MainWindow";

      auto pred = [&s, &mw](xml_node &nd)
                  { return nd.name() != s;  };

      xml_node header = doc.child("Settings"), sett_gui = header.child("GUI"),
               sett_gui_mw = sett_gui.child("MainWindow");
      //xml_node sett_size = sett_gui_mw.find_child_by_attribute("size", "height", "400");
      xml_node sett_size = sett_gui_mw.find_child(pred);
      print_ln(sett_size.name());
   }

   void example2()
   {
      settings st;

      item_group core =  st.add_group("Core", 1);
      item_group events = st.add_sub_group(core, "Events");
      events.append_child("DragEvent").append_attribute("avail").set_value("true");

      item_group gui = st.add_group("GUI", 2);
      st.add_sub_group(gui, "MainWindow")
        .append_child("size").append_attribute("height").set_value("9");

      st.save_file("ss2.xml");
   }

   void main()
   {
      //example();
      //example1();
      example2();
   }
}

#endif//COMBIN~1_H
