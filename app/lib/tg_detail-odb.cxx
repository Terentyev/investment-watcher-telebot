// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "tg_detail-odb.hxx"

#include <cassert>
#include <cstring>  // std::memcpy

#include <odb/schema-catalog-impl.hxx>

#include <odb/sqlite/traits.hxx>
#include <odb/sqlite/database.hxx>
#include <odb/sqlite/transaction.hxx>
#include <odb/sqlite/connection.hxx>
#include <odb/sqlite/statement.hxx>
#include <odb/sqlite/statement-cache.hxx>
#include <odb/sqlite/simple-object-statements.hxx>
#include <odb/sqlite/container-statements.hxx>
#include <odb/sqlite/exceptions.hxx>
#include <odb/sqlite/simple-object-result.hxx>

namespace odb
{
  // tg_detail
  //

  struct access::object_traits_impl< ::tg_detail, id_sqlite >::extra_statement_cache_type
  {
    extra_statement_cache_type (
      sqlite::connection&,
      image_type&,
      id_image_type&,
      sqlite::binding&,
      sqlite::binding&)
    {
    }
  };

  access::object_traits_impl< ::tg_detail, id_sqlite >::id_type
  access::object_traits_impl< ::tg_detail, id_sqlite >::
  id (const image_type& i)
  {
    sqlite::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      sqlite::value_traits<
          long unsigned int,
          sqlite::id_integer >::set_value (
        id,
        i.id_value,
        i.id_null);
    }

    return id;
  }

  bool access::object_traits_impl< ::tg_detail, id_sqlite >::
  grow (image_type& i,
        bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // id_
    //
    t[0UL] = false;

    // tgid_
    //
    t[1UL] = false;

    // username_
    //
    if (t[2UL])
    {
      i.username_value.capacity (i.username_size);
      grew = true;
    }

    // first_name_
    //
    if (t[3UL])
    {
      i.first_name_value.capacity (i.first_name_size);
      grew = true;
    }

    // last_name_
    //
    if (t[4UL])
    {
      i.last_name_value.capacity (i.last_name_size);
      grew = true;
    }

    // language_code_
    //
    if (t[5UL])
    {
      i.language_code_value.capacity (i.language_code_size);
      grew = true;
    }

    // is_bot_
    //
    t[6UL] = false;

    // user_id_
    //
    t[7UL] = false;

    return grew;
  }

  void access::object_traits_impl< ::tg_detail, id_sqlite >::
  bind (sqlite::bind* b,
        image_type& i,
        sqlite::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace sqlite;

    std::size_t n (0);

    // id_
    //
    if (sk != statement_update)
    {
      b[n].type = sqlite::bind::integer;
      b[n].buffer = &i.id_value;
      b[n].is_null = &i.id_null;
      n++;
    }

    // tgid_
    //
    b[n].type = sqlite::bind::integer;
    b[n].buffer = &i.tgid_value;
    b[n].is_null = &i.tgid_null;
    n++;

    // username_
    //
    b[n].type = sqlite::image_traits<
      ::std::string,
      sqlite::id_text>::bind_value;
    b[n].buffer = i.username_value.data ();
    b[n].size = &i.username_size;
    b[n].capacity = i.username_value.capacity ();
    b[n].is_null = &i.username_null;
    n++;

    // first_name_
    //
    b[n].type = sqlite::image_traits<
      ::std::string,
      sqlite::id_text>::bind_value;
    b[n].buffer = i.first_name_value.data ();
    b[n].size = &i.first_name_size;
    b[n].capacity = i.first_name_value.capacity ();
    b[n].is_null = &i.first_name_null;
    n++;

    // last_name_
    //
    b[n].type = sqlite::image_traits<
      ::std::string,
      sqlite::id_text>::bind_value;
    b[n].buffer = i.last_name_value.data ();
    b[n].size = &i.last_name_size;
    b[n].capacity = i.last_name_value.capacity ();
    b[n].is_null = &i.last_name_null;
    n++;

    // language_code_
    //
    b[n].type = sqlite::image_traits<
      ::std::string,
      sqlite::id_text>::bind_value;
    b[n].buffer = i.language_code_value.data ();
    b[n].size = &i.language_code_size;
    b[n].capacity = i.language_code_value.capacity ();
    b[n].is_null = &i.language_code_null;
    n++;

    // is_bot_
    //
    b[n].type = sqlite::bind::integer;
    b[n].buffer = &i.is_bot_value;
    b[n].is_null = &i.is_bot_null;
    n++;

    // user_id_
    //
    b[n].type = sqlite::bind::integer;
    b[n].buffer = &i.user_id_value;
    b[n].is_null = &i.user_id_null;
    n++;
  }

  void access::object_traits_impl< ::tg_detail, id_sqlite >::
  bind (sqlite::bind* b, id_image_type& i)
  {
    std::size_t n (0);
    b[n].type = sqlite::bind::integer;
    b[n].buffer = &i.id_value;
    b[n].is_null = &i.id_null;
  }

  bool access::object_traits_impl< ::tg_detail, id_sqlite >::
  init (image_type& i,
        const object_type& o,
        sqlite::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace sqlite;

    bool grew (false);

    // id_
    //
    if (sk == statement_insert)
    {
      long unsigned int const& v =
        o.id_;

      bool is_null (false);
      sqlite::value_traits<
          long unsigned int,
          sqlite::id_integer >::set_image (
        i.id_value,
        is_null,
        v);
      i.id_null = is_null;
    }

    // tgid_
    //
    {
      ::int64_t const& v =
        o.tgid_;

      bool is_null (false);
      sqlite::value_traits<
          ::int64_t,
          sqlite::id_integer >::set_image (
        i.tgid_value,
        is_null,
        v);
      i.tgid_null = is_null;
    }

    // username_
    //
    {
      ::std::string const& v =
        o.username_;

      bool is_null (false);
      std::size_t cap (i.username_value.capacity ());
      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_image (
        i.username_value,
        i.username_size,
        is_null,
        v);
      i.username_null = is_null;
      grew = grew || (cap != i.username_value.capacity ());
    }

    // first_name_
    //
    {
      ::std::string const& v =
        o.first_name_;

      bool is_null (false);
      std::size_t cap (i.first_name_value.capacity ());
      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_image (
        i.first_name_value,
        i.first_name_size,
        is_null,
        v);
      i.first_name_null = is_null;
      grew = grew || (cap != i.first_name_value.capacity ());
    }

    // last_name_
    //
    {
      ::std::string const& v =
        o.last_name_;

      bool is_null (false);
      std::size_t cap (i.last_name_value.capacity ());
      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_image (
        i.last_name_value,
        i.last_name_size,
        is_null,
        v);
      i.last_name_null = is_null;
      grew = grew || (cap != i.last_name_value.capacity ());
    }

    // language_code_
    //
    {
      ::std::string const& v =
        o.language_code_;

      bool is_null (false);
      std::size_t cap (i.language_code_value.capacity ());
      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_image (
        i.language_code_value,
        i.language_code_size,
        is_null,
        v);
      i.language_code_null = is_null;
      grew = grew || (cap != i.language_code_value.capacity ());
    }

    // is_bot_
    //
    {
      bool const& v =
        o.is_bot_;

      bool is_null (false);
      sqlite::value_traits<
          bool,
          sqlite::id_integer >::set_image (
        i.is_bot_value,
        is_null,
        v);
      i.is_bot_null = is_null;
    }

    // user_id_
    //
    {
      long unsigned int const& v =
        o.user_id_;

      bool is_null (false);
      sqlite::value_traits<
          long unsigned int,
          sqlite::id_integer >::set_image (
        i.user_id_value,
        is_null,
        v);
      i.user_id_null = is_null;
    }

    return grew;
  }

  void access::object_traits_impl< ::tg_detail, id_sqlite >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // id_
    //
    {
      long unsigned int& v =
        o.id_;

      sqlite::value_traits<
          long unsigned int,
          sqlite::id_integer >::set_value (
        v,
        i.id_value,
        i.id_null);
    }

    // tgid_
    //
    {
      ::int64_t& v =
        o.tgid_;

      sqlite::value_traits<
          ::int64_t,
          sqlite::id_integer >::set_value (
        v,
        i.tgid_value,
        i.tgid_null);
    }

    // username_
    //
    {
      ::std::string& v =
        o.username_;

      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_value (
        v,
        i.username_value,
        i.username_size,
        i.username_null);
    }

    // first_name_
    //
    {
      ::std::string& v =
        o.first_name_;

      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_value (
        v,
        i.first_name_value,
        i.first_name_size,
        i.first_name_null);
    }

    // last_name_
    //
    {
      ::std::string& v =
        o.last_name_;

      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_value (
        v,
        i.last_name_value,
        i.last_name_size,
        i.last_name_null);
    }

    // language_code_
    //
    {
      ::std::string& v =
        o.language_code_;

      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_value (
        v,
        i.language_code_value,
        i.language_code_size,
        i.language_code_null);
    }

    // is_bot_
    //
    {
      bool& v =
        o.is_bot_;

      sqlite::value_traits<
          bool,
          sqlite::id_integer >::set_value (
        v,
        i.is_bot_value,
        i.is_bot_null);
    }

    // user_id_
    //
    {
      long unsigned int& v =
        o.user_id_;

      sqlite::value_traits<
          long unsigned int,
          sqlite::id_integer >::set_value (
        v,
        i.user_id_value,
        i.user_id_null);
    }
  }

  void access::object_traits_impl< ::tg_detail, id_sqlite >::
  init (id_image_type& i, const id_type& id)
  {
    {
      bool is_null (false);
      sqlite::value_traits<
          long unsigned int,
          sqlite::id_integer >::set_image (
        i.id_value,
        is_null,
        id);
      i.id_null = is_null;
    }
  }

  const char access::object_traits_impl< ::tg_detail, id_sqlite >::persist_statement[] =
  "INSERT INTO \"tg_details\" "
  "(\"id\", "
  "\"tgid\", "
  "\"username\", "
  "\"first_name\", "
  "\"last_name\", "
  "\"language_code\", "
  "\"is_bot\", "
  "\"user_id\") "
  "VALUES "
  "(?, ?, ?, ?, ?, ?, ?, ?)";

  const char access::object_traits_impl< ::tg_detail, id_sqlite >::find_statement[] =
  "SELECT "
  "\"tg_details\".\"id\", "
  "\"tg_details\".\"tgid\", "
  "\"tg_details\".\"username\", "
  "\"tg_details\".\"first_name\", "
  "\"tg_details\".\"last_name\", "
  "\"tg_details\".\"language_code\", "
  "\"tg_details\".\"is_bot\", "
  "\"tg_details\".\"user_id\" "
  "FROM \"tg_details\" "
  "WHERE \"tg_details\".\"id\"=?";

  const char access::object_traits_impl< ::tg_detail, id_sqlite >::update_statement[] =
  "UPDATE \"tg_details\" "
  "SET "
  "\"tgid\"=?, "
  "\"username\"=?, "
  "\"first_name\"=?, "
  "\"last_name\"=?, "
  "\"language_code\"=?, "
  "\"is_bot\"=?, "
  "\"user_id\"=? "
  "WHERE \"id\"=?";

  const char access::object_traits_impl< ::tg_detail, id_sqlite >::erase_statement[] =
  "DELETE FROM \"tg_details\" "
  "WHERE \"id\"=?";

  const char access::object_traits_impl< ::tg_detail, id_sqlite >::query_statement[] =
  "SELECT "
  "\"tg_details\".\"id\", "
  "\"tg_details\".\"tgid\", "
  "\"tg_details\".\"username\", "
  "\"tg_details\".\"first_name\", "
  "\"tg_details\".\"last_name\", "
  "\"tg_details\".\"language_code\", "
  "\"tg_details\".\"is_bot\", "
  "\"tg_details\".\"user_id\" "
  "FROM \"tg_details\"";

  const char access::object_traits_impl< ::tg_detail, id_sqlite >::erase_query_statement[] =
  "DELETE FROM \"tg_details\"";

  const char access::object_traits_impl< ::tg_detail, id_sqlite >::table_name[] =
  "\"tg_details\"";

  void access::object_traits_impl< ::tg_detail, id_sqlite >::
  persist (database& db, const object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace sqlite;

    sqlite::connection& conn (
      sqlite::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    callback (db,
              obj,
              callback_event::pre_persist);

    image_type& im (sts.image ());
    binding& imb (sts.insert_image_binding ());

    if (init (im, obj, statement_insert))
      im.version++;

    if (im.version != sts.insert_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_insert);
      sts.insert_image_version (im.version);
      imb.version++;
    }

    insert_statement& st (sts.persist_statement ());
    if (!st.execute ())
      throw object_already_persistent ();

    callback (db,
              obj,
              callback_event::post_persist);
  }

  void access::object_traits_impl< ::tg_detail, id_sqlite >::
  update (database& db, const object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace sqlite;
    using sqlite::update_statement;

    callback (db, obj, callback_event::pre_update);

    sqlite::transaction& tr (sqlite::transaction::current ());
    sqlite::connection& conn (tr.connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    const id_type& id (
      obj.id_);
    id_image_type& idi (sts.id_image ());
    init (idi, id);

    image_type& im (sts.image ());
    if (init (im, obj, statement_update))
      im.version++;

    bool u (false);
    binding& imb (sts.update_image_binding ());
    if (im.version != sts.update_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_update);
      sts.update_image_version (im.version);
      imb.version++;
      u = true;
    }

    binding& idb (sts.id_image_binding ());
    if (idi.version != sts.update_id_image_version () ||
        idb.version == 0)
    {
      if (idi.version != sts.id_image_version () ||
          idb.version == 0)
      {
        bind (idb.bind, idi);
        sts.id_image_version (idi.version);
        idb.version++;
      }

      sts.update_id_image_version (idi.version);

      if (!u)
        imb.version++;
    }

    update_statement& st (sts.update_statement ());
    if (st.execute () == 0)
      throw object_not_persistent ();

    callback (db, obj, callback_event::post_update);
    pointer_cache_traits::update (db, obj);
  }

  void access::object_traits_impl< ::tg_detail, id_sqlite >::
  erase (database& db, const id_type& id)
  {
    using namespace sqlite;

    ODB_POTENTIALLY_UNUSED (db);

    sqlite::connection& conn (
      sqlite::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    id_image_type& i (sts.id_image ());
    init (i, id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    if (sts.erase_statement ().execute () != 1)
      throw object_not_persistent ();

    pointer_cache_traits::erase (db, id);
  }

  access::object_traits_impl< ::tg_detail, id_sqlite >::pointer_type
  access::object_traits_impl< ::tg_detail, id_sqlite >::
  find (database& db, const id_type& id)
  {
    using namespace sqlite;

    {
      pointer_type p (pointer_cache_traits::find (db, id));

      if (!pointer_traits::null_ptr (p))
        return p;
    }

    sqlite::connection& conn (
      sqlite::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (l.locked ())
    {
      if (!find_ (sts, &id))
        return pointer_type ();
    }

    pointer_type p (
      access::object_factory<object_type, pointer_type>::create ());
    pointer_traits::guard pg (p);

    pointer_cache_traits::insert_guard ig (
      pointer_cache_traits::insert (db, id, p));

    object_type& obj (pointer_traits::get_ref (p));

    if (l.locked ())
    {
      select_statement& st (sts.find_statement ());
      ODB_POTENTIALLY_UNUSED (st);

      callback (db, obj, callback_event::pre_load);
      init (obj, sts.image (), &db);
      load_ (sts, obj, false);
      sts.load_delayed (0);
      l.unlock ();
      callback (db, obj, callback_event::post_load);
      pointer_cache_traits::load (ig.position ());
    }
    else
      sts.delay_load (id, obj, ig.position ());

    ig.release ();
    pg.release ();
    return p;
  }

  bool access::object_traits_impl< ::tg_detail, id_sqlite >::
  find (database& db, const id_type& id, object_type& obj)
  {
    using namespace sqlite;

    sqlite::connection& conn (
      sqlite::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    reference_cache_traits::position_type pos (
      reference_cache_traits::insert (db, id, obj));
    reference_cache_traits::insert_guard ig (pos);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, false);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    reference_cache_traits::load (pos);
    ig.release ();
    return true;
  }

  bool access::object_traits_impl< ::tg_detail, id_sqlite >::
  reload (database& db, object_type& obj)
  {
    using namespace sqlite;

    sqlite::connection& conn (
      sqlite::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    const id_type& id  (
      obj.id_);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, true);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    return true;
  }

  bool access::object_traits_impl< ::tg_detail, id_sqlite >::
  find_ (statements_type& sts,
         const id_type* id)
  {
    using namespace sqlite;

    id_image_type& i (sts.id_image ());
    init (i, *id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    select_statement& st (sts.find_statement ());

    st.execute ();
    auto_result ar (st);
    select_statement::result r (st.fetch ());

    if (r == select_statement::truncated)
    {
      if (grow (im, sts.select_image_truncated ()))
        im.version++;

      if (im.version != sts.select_image_version ())
      {
        bind (imb.bind, im, statement_select);
        sts.select_image_version (im.version);
        imb.version++;
        st.refetch ();
      }
    }

    return r != select_statement::no_data;
  }

  result< access::object_traits_impl< ::tg_detail, id_sqlite >::object_type >
  access::object_traits_impl< ::tg_detail, id_sqlite >::
  query (database&, const query_base_type& q)
  {
    using namespace sqlite;
    using odb::details::shared;
    using odb::details::shared_ptr;

    sqlite::connection& conn (
      sqlite::transaction::current ().connection ());

    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    std::string text (query_statement);
    if (!q.empty ())
    {
      text += " ";
      text += q.clause ();
    }

    q.init_parameters ();
    shared_ptr<select_statement> st (
      new (shared) select_statement (
        conn,
        text,
        false,
        true,
        q.parameters_binding (),
        imb));

    st->execute ();

    shared_ptr< odb::object_result_impl<object_type> > r (
      new (shared) sqlite::object_result_impl<object_type> (
        q, st, sts, 0));

    return result<object_type> (r);
  }

  unsigned long long access::object_traits_impl< ::tg_detail, id_sqlite >::
  erase_query (database&, const query_base_type& q)
  {
    using namespace sqlite;

    sqlite::connection& conn (
      sqlite::transaction::current ().connection ());

    std::string text (erase_query_statement);
    if (!q.empty ())
    {
      text += ' ';
      text += q.clause ();
    }

    q.init_parameters ();
    delete_statement st (
      conn,
      text,
      q.parameters_binding ());

    return st.execute ();
  }
}

namespace odb
{
  static bool
  create_schema (database& db, unsigned short pass, bool drop)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (pass);
    ODB_POTENTIALLY_UNUSED (drop);

    if (drop)
    {
      switch (pass)
      {
        case 1:
        {
          return true;
        }
        case 2:
        {
          db.execute ("DROP TABLE IF EXISTS \"tg_details\"");
          return false;
        }
      }
    }
    else
    {
      switch (pass)
      {
        case 1:
        {
          db.execute ("CREATE TABLE \"tg_details\" (\n"
                      "  \"id\" INTEGER NOT NULL PRIMARY KEY,\n"
                      "  \"tgid\" INTEGER NOT NULL,\n"
                      "  \"username\" VARCHAR(128) NOT NULL,\n"
                      "  \"first_name\" VARCHAR(128) NOT NULL,\n"
                      "  \"last_name\" VARCHAR(128) NOT NULL,\n"
                      "  \"language_code\" VARCHAR(8) NOT NULL,\n"
                      "  \"is_bot\" INTEGER NOT NULL,\n"
                      "  \"user_id\" INTEGER NOT NULL)");
          return false;
        }
      }
    }

    return false;
  }

  static const schema_catalog_create_entry
  create_schema_entry_ (
    id_sqlite,
    "",
    &create_schema);
}

#include <odb/post.hxx>
