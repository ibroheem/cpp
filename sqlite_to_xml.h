#ifndef HEADER_DC7527D187C1340
#define HEADER_DC7527D187C1340

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlField>

#include <mib/io.h>
#include <mib/string_operations.h>
#include <mib/pugi/operations.h>

using namespace mvc_utils::io;
using mvc_utils::string_operations::file_name_w_ext;
using namespace pugi;
using namespace std;

using namespace pugi_operations;

namespace conversion
{
#ifdef SOCI_H_INCLUDED
  #include <soci/soci.h>
  #include <soci/soci-sqlite3.h>
  class sqlite_to_xml_soci
  {
    public:
      sqlite_to_xml_soci() = default;
  };

#endif // SOCI_H_INCLUDED


//#ifndef QSQLDATABASE_H

  class sqlite_to_xml_Qt
  {
    public:
      sqlite_to_xml_Qt() = default;
      sqlite_to_xml_Qt (cchar *);
      sqlite_to_xml_Qt (cchar *, cchar *);

      void set_src_db_name (const char *_name)
      {  m_db_name = _name; }

      void set_src_db_name (const string &_name)
      {  set_src_db_name(_name.c_str()); }

      void set_src_db_name (const QString &_name) {  set_src_db_name (_name.toStdString().c_str()); };

      void set_output_name (const char *_name) {  m_xml_name = _name; };
      void set_output_name (const QString &_name) {  set_output_name (_name); };

      void convert();

      void convert_n_write() { convert_n_write(m_xml_name); };
      void convert_n_write (cchar * _out_name) { convert(); write_file(_out_name); }
#ifdef QSTRING_H
      void convert_n_write (QString& _out_name) { convert(); write_file(_out_name.toLatin1()); }
#endif // QSTRING_H

      QSqlDatabase& database() { return m_database; }

      bool open_database_conn() { return m_database.open();}
      void set_database_name()  { m_database.setDatabaseName (m_db_name); };
      void set_database_name(cchar *_name)  { m_database.setDatabaseName(_name); };

      /** clears the xml internal document content(the output file's nor database's)  */
      void reset_xml_doc() { doc.reset(); }

      /** clears the xml internal document content(the output file's nor database's) and creates a child in which
       other children might be added  */
      void reset_xml_doc_w_child(cchar *_header) { doc.reset(); header = doc.append_child (_header); }

      /** writes/saves the result of the conversion prcc to _output_name, conversion must've been done */
      void write_file() { write_file (m_xml_name); };
      void write_file (cchar* _output_name) { doc.save_file (_output_name); };

    public:
      bool is_open() { return m_database.isOpen(); }
      cchar* output_name() { return m_xml_name; }

    private:
      cchar* m_db_name = "", * m_xml_name = "output.xml";
      QSqlDatabase m_database = QSqlDatabase::addDatabase ("QSQLITE");

      QStringList m_tables;

      xml_document doc;
      xml_node header = doc.append_child ("header");

  };

  /** Ctor taking only database name, output.xml is the name of the generated output*/
  sqlite_to_xml_Qt::sqlite_to_xml_Qt (cchar * _db_name) : m_db_name (_db_name)
  {

  }

  /** _db_name is the database name, _output_name is the name of the generated output*/
  sqlite_to_xml_Qt::sqlite_to_xml_Qt (cchar* _db_name, cchar * _output_name) : m_db_name (_db_name),
                                                                               m_xml_name (_output_name)
  {

  }

  /** Does the conversion sets db name, opens it, get tables, creates query, then db is read for conversion to xml.
      Does not do the saving to file
   */
  void sqlite_to_xml_Qt::convert ()
  {
    set_database_name();
    open_database_conn();
    m_tables = m_database.tables();
    append_attribute(header, "database_name", file_name_w_ext(m_database.databaseName().toStdString()).c_str());

    for (int i = 0; i < m_tables.size(); ++i)
    {
      QSqlQuery query ("SELECT * FROM " + m_tables[i], m_database);

      int l = 1, rec_len = query.record().count();

      xml_node table = append_child (header, "table");
      append_attribute(table, "name", m_tables[i]);

      while (query.next())
      {
        xml_node row = append_child (table, "row");
        row.append_attribute("row_id").set_value(l);

        for (int j = 0; j < rec_len; ++j)
          append_attribute (row, query.record().fieldName (j), query.value (j).toString() );
        ++l;
      }
    }
  }

  void usage()
  {
    {
    /*sqlite_to_xml_Qt proj("/home/ibroheem/usr/devs/sql/Book2.db", "Book1.xml");
    proj.convert_n_write();
    proj.reset_xml_doc_w_child("header"); //If not called, new conversion will be appended

    proj.set_db_name("/home/ibroheem/usr/devs/sql/Book10.db");
    proj.set_output_name("Book10.xml");
    proj.convert_n_write();*/
    }
  }

//#endif // QSQLDATABASE_H
}

#endif // header guard
