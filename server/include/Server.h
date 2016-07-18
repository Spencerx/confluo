/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Server_H
#define Server_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "server_types.h"

namespace succinct {

#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class ServerIf {
 public:
  virtual ~ServerIf() {}
  virtual int32_t Initialize() = 0;
  virtual void Append(const int64_t key, const std::string& value) = 0;
  virtual void Get(std::string& _return, const int64_t key) = 0;
  virtual void Search(std::vector<int64_t> & _return, const std::string& query) = 0;
  virtual void Delete(const int64_t key) = 0;
  virtual int64_t GetNumKeys() = 0;
  virtual int64_t GetSize() = 0;
};

class ServerIfFactory {
 public:
  typedef ServerIf Handler;

  virtual ~ServerIfFactory() {}

  virtual ServerIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ServerIf* /* handler */) = 0;
};

class ServerIfSingletonFactory : virtual public ServerIfFactory {
 public:
  ServerIfSingletonFactory(const boost::shared_ptr<ServerIf>& iface) : iface_(iface) {}
  virtual ~ServerIfSingletonFactory() {}

  virtual ServerIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ServerIf* /* handler */) {}

 protected:
  boost::shared_ptr<ServerIf> iface_;
};

class ServerNull : virtual public ServerIf {
 public:
  virtual ~ServerNull() {}
  int32_t Initialize() {
    int32_t _return = 0;
    return _return;
  }
  void Append(const int64_t /* key */, const std::string& /* value */) {
    return;
  }
  void Get(std::string& /* _return */, const int64_t /* key */) {
    return;
  }
  void Search(std::vector<int64_t> & /* _return */, const std::string& /* query */) {
    return;
  }
  void Delete(const int64_t /* key */) {
    return;
  }
  int64_t GetNumKeys() {
    int64_t _return = 0;
    return _return;
  }
  int64_t GetSize() {
    int64_t _return = 0;
    return _return;
  }
};


class Server_Initialize_args {
 public:

  Server_Initialize_args(const Server_Initialize_args&);
  Server_Initialize_args& operator=(const Server_Initialize_args&);
  Server_Initialize_args() {
  }

  virtual ~Server_Initialize_args() throw();

  bool operator == (const Server_Initialize_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Server_Initialize_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Server_Initialize_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Server_Initialize_pargs {
 public:


  virtual ~Server_Initialize_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Server_Initialize_result__isset {
  _Server_Initialize_result__isset() : success(false) {}
  bool success :1;
} _Server_Initialize_result__isset;

class Server_Initialize_result {
 public:

  Server_Initialize_result(const Server_Initialize_result&);
  Server_Initialize_result& operator=(const Server_Initialize_result&);
  Server_Initialize_result() : success(0) {
  }

  virtual ~Server_Initialize_result() throw();
  int32_t success;

  _Server_Initialize_result__isset __isset;

  void __set_success(const int32_t val);

  bool operator == (const Server_Initialize_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Server_Initialize_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Server_Initialize_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Server_Initialize_presult__isset {
  _Server_Initialize_presult__isset() : success(false) {}
  bool success :1;
} _Server_Initialize_presult__isset;

class Server_Initialize_presult {
 public:


  virtual ~Server_Initialize_presult() throw();
  int32_t* success;

  _Server_Initialize_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Server_Append_args__isset {
  _Server_Append_args__isset() : key(false), value(false) {}
  bool key :1;
  bool value :1;
} _Server_Append_args__isset;

class Server_Append_args {
 public:

  Server_Append_args(const Server_Append_args&);
  Server_Append_args& operator=(const Server_Append_args&);
  Server_Append_args() : key(0), value() {
  }

  virtual ~Server_Append_args() throw();
  int64_t key;
  std::string value;

  _Server_Append_args__isset __isset;

  void __set_key(const int64_t val);

  void __set_value(const std::string& val);

  bool operator == (const Server_Append_args & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    if (!(value == rhs.value))
      return false;
    return true;
  }
  bool operator != (const Server_Append_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Server_Append_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Server_Append_pargs {
 public:


  virtual ~Server_Append_pargs() throw();
  const int64_t* key;
  const std::string* value;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Server_Append_result {
 public:

  Server_Append_result(const Server_Append_result&);
  Server_Append_result& operator=(const Server_Append_result&);
  Server_Append_result() {
  }

  virtual ~Server_Append_result() throw();

  bool operator == (const Server_Append_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Server_Append_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Server_Append_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Server_Append_presult {
 public:


  virtual ~Server_Append_presult() throw();

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Server_Get_args__isset {
  _Server_Get_args__isset() : key(false) {}
  bool key :1;
} _Server_Get_args__isset;

class Server_Get_args {
 public:

  Server_Get_args(const Server_Get_args&);
  Server_Get_args& operator=(const Server_Get_args&);
  Server_Get_args() : key(0) {
  }

  virtual ~Server_Get_args() throw();
  int64_t key;

  _Server_Get_args__isset __isset;

  void __set_key(const int64_t val);

  bool operator == (const Server_Get_args & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    return true;
  }
  bool operator != (const Server_Get_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Server_Get_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Server_Get_pargs {
 public:


  virtual ~Server_Get_pargs() throw();
  const int64_t* key;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Server_Get_result__isset {
  _Server_Get_result__isset() : success(false) {}
  bool success :1;
} _Server_Get_result__isset;

class Server_Get_result {
 public:

  Server_Get_result(const Server_Get_result&);
  Server_Get_result& operator=(const Server_Get_result&);
  Server_Get_result() : success() {
  }

  virtual ~Server_Get_result() throw();
  std::string success;

  _Server_Get_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const Server_Get_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Server_Get_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Server_Get_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Server_Get_presult__isset {
  _Server_Get_presult__isset() : success(false) {}
  bool success :1;
} _Server_Get_presult__isset;

class Server_Get_presult {
 public:


  virtual ~Server_Get_presult() throw();
  std::string* success;

  _Server_Get_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Server_Search_args__isset {
  _Server_Search_args__isset() : query(false) {}
  bool query :1;
} _Server_Search_args__isset;

class Server_Search_args {
 public:

  Server_Search_args(const Server_Search_args&);
  Server_Search_args& operator=(const Server_Search_args&);
  Server_Search_args() : query() {
  }

  virtual ~Server_Search_args() throw();
  std::string query;

  _Server_Search_args__isset __isset;

  void __set_query(const std::string& val);

  bool operator == (const Server_Search_args & rhs) const
  {
    if (!(query == rhs.query))
      return false;
    return true;
  }
  bool operator != (const Server_Search_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Server_Search_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Server_Search_pargs {
 public:


  virtual ~Server_Search_pargs() throw();
  const std::string* query;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Server_Search_result__isset {
  _Server_Search_result__isset() : success(false) {}
  bool success :1;
} _Server_Search_result__isset;

class Server_Search_result {
 public:

  Server_Search_result(const Server_Search_result&);
  Server_Search_result& operator=(const Server_Search_result&);
  Server_Search_result() {
  }

  virtual ~Server_Search_result() throw();
  std::vector<int64_t>  success;

  _Server_Search_result__isset __isset;

  void __set_success(const std::vector<int64_t> & val);

  bool operator == (const Server_Search_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Server_Search_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Server_Search_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Server_Search_presult__isset {
  _Server_Search_presult__isset() : success(false) {}
  bool success :1;
} _Server_Search_presult__isset;

class Server_Search_presult {
 public:


  virtual ~Server_Search_presult() throw();
  std::vector<int64_t> * success;

  _Server_Search_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Server_Delete_args__isset {
  _Server_Delete_args__isset() : key(false) {}
  bool key :1;
} _Server_Delete_args__isset;

class Server_Delete_args {
 public:

  Server_Delete_args(const Server_Delete_args&);
  Server_Delete_args& operator=(const Server_Delete_args&);
  Server_Delete_args() : key(0) {
  }

  virtual ~Server_Delete_args() throw();
  int64_t key;

  _Server_Delete_args__isset __isset;

  void __set_key(const int64_t val);

  bool operator == (const Server_Delete_args & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    return true;
  }
  bool operator != (const Server_Delete_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Server_Delete_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Server_Delete_pargs {
 public:


  virtual ~Server_Delete_pargs() throw();
  const int64_t* key;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Server_Delete_result {
 public:

  Server_Delete_result(const Server_Delete_result&);
  Server_Delete_result& operator=(const Server_Delete_result&);
  Server_Delete_result() {
  }

  virtual ~Server_Delete_result() throw();

  bool operator == (const Server_Delete_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Server_Delete_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Server_Delete_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Server_Delete_presult {
 public:


  virtual ~Server_Delete_presult() throw();

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class Server_GetNumKeys_args {
 public:

  Server_GetNumKeys_args(const Server_GetNumKeys_args&);
  Server_GetNumKeys_args& operator=(const Server_GetNumKeys_args&);
  Server_GetNumKeys_args() {
  }

  virtual ~Server_GetNumKeys_args() throw();

  bool operator == (const Server_GetNumKeys_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Server_GetNumKeys_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Server_GetNumKeys_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Server_GetNumKeys_pargs {
 public:


  virtual ~Server_GetNumKeys_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Server_GetNumKeys_result__isset {
  _Server_GetNumKeys_result__isset() : success(false) {}
  bool success :1;
} _Server_GetNumKeys_result__isset;

class Server_GetNumKeys_result {
 public:

  Server_GetNumKeys_result(const Server_GetNumKeys_result&);
  Server_GetNumKeys_result& operator=(const Server_GetNumKeys_result&);
  Server_GetNumKeys_result() : success(0) {
  }

  virtual ~Server_GetNumKeys_result() throw();
  int64_t success;

  _Server_GetNumKeys_result__isset __isset;

  void __set_success(const int64_t val);

  bool operator == (const Server_GetNumKeys_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Server_GetNumKeys_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Server_GetNumKeys_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Server_GetNumKeys_presult__isset {
  _Server_GetNumKeys_presult__isset() : success(false) {}
  bool success :1;
} _Server_GetNumKeys_presult__isset;

class Server_GetNumKeys_presult {
 public:


  virtual ~Server_GetNumKeys_presult() throw();
  int64_t* success;

  _Server_GetNumKeys_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class Server_GetSize_args {
 public:

  Server_GetSize_args(const Server_GetSize_args&);
  Server_GetSize_args& operator=(const Server_GetSize_args&);
  Server_GetSize_args() {
  }

  virtual ~Server_GetSize_args() throw();

  bool operator == (const Server_GetSize_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Server_GetSize_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Server_GetSize_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Server_GetSize_pargs {
 public:


  virtual ~Server_GetSize_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Server_GetSize_result__isset {
  _Server_GetSize_result__isset() : success(false) {}
  bool success :1;
} _Server_GetSize_result__isset;

class Server_GetSize_result {
 public:

  Server_GetSize_result(const Server_GetSize_result&);
  Server_GetSize_result& operator=(const Server_GetSize_result&);
  Server_GetSize_result() : success(0) {
  }

  virtual ~Server_GetSize_result() throw();
  int64_t success;

  _Server_GetSize_result__isset __isset;

  void __set_success(const int64_t val);

  bool operator == (const Server_GetSize_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Server_GetSize_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Server_GetSize_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Server_GetSize_presult__isset {
  _Server_GetSize_presult__isset() : success(false) {}
  bool success :1;
} _Server_GetSize_presult__isset;

class Server_GetSize_presult {
 public:


  virtual ~Server_GetSize_presult() throw();
  int64_t* success;

  _Server_GetSize_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class ServerClient : virtual public ServerIf {
 public:
  ServerClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  ServerClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int32_t Initialize();
  void send_Initialize();
  int32_t recv_Initialize();
  void Append(const int64_t key, const std::string& value);
  void send_Append(const int64_t key, const std::string& value);
  void recv_Append();
  void Get(std::string& _return, const int64_t key);
  void send_Get(const int64_t key);
  void recv_Get(std::string& _return);
  void Search(std::vector<int64_t> & _return, const std::string& query);
  void send_Search(const std::string& query);
  void recv_Search(std::vector<int64_t> & _return);
  void Delete(const int64_t key);
  void send_Delete(const int64_t key);
  void recv_Delete();
  int64_t GetNumKeys();
  void send_GetNumKeys();
  int64_t recv_GetNumKeys();
  int64_t GetSize();
  void send_GetSize();
  int64_t recv_GetSize();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class ServerProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<ServerIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (ServerProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_Initialize(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_Append(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_Get(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_Search(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_Delete(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_GetNumKeys(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_GetSize(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ServerProcessor(boost::shared_ptr<ServerIf> iface) :
    iface_(iface) {
    processMap_["Initialize"] = &ServerProcessor::process_Initialize;
    processMap_["Append"] = &ServerProcessor::process_Append;
    processMap_["Get"] = &ServerProcessor::process_Get;
    processMap_["Search"] = &ServerProcessor::process_Search;
    processMap_["Delete"] = &ServerProcessor::process_Delete;
    processMap_["GetNumKeys"] = &ServerProcessor::process_GetNumKeys;
    processMap_["GetSize"] = &ServerProcessor::process_GetSize;
  }

  virtual ~ServerProcessor() {}
};

class ServerProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  ServerProcessorFactory(const ::boost::shared_ptr< ServerIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< ServerIfFactory > handlerFactory_;
};

class ServerMultiface : virtual public ServerIf {
 public:
  ServerMultiface(std::vector<boost::shared_ptr<ServerIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~ServerMultiface() {}
 protected:
  std::vector<boost::shared_ptr<ServerIf> > ifaces_;
  ServerMultiface() {}
  void add(boost::shared_ptr<ServerIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  int32_t Initialize() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Initialize();
    }
    return ifaces_[i]->Initialize();
  }

  void Append(const int64_t key, const std::string& value) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Append(key, value);
    }
    ifaces_[i]->Append(key, value);
  }

  void Get(std::string& _return, const int64_t key) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Get(_return, key);
    }
    ifaces_[i]->Get(_return, key);
    return;
  }

  void Search(std::vector<int64_t> & _return, const std::string& query) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Search(_return, query);
    }
    ifaces_[i]->Search(_return, query);
    return;
  }

  void Delete(const int64_t key) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Delete(key);
    }
    ifaces_[i]->Delete(key);
  }

  int64_t GetNumKeys() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->GetNumKeys();
    }
    return ifaces_[i]->GetNumKeys();
  }

  int64_t GetSize() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->GetSize();
    }
    return ifaces_[i]->GetSize();
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class ServerConcurrentClient : virtual public ServerIf {
 public:
  ServerConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  ServerConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int32_t Initialize();
  int32_t send_Initialize();
  int32_t recv_Initialize(const int32_t seqid);
  void Append(const int64_t key, const std::string& value);
  int32_t send_Append(const int64_t key, const std::string& value);
  void recv_Append(const int32_t seqid);
  void Get(std::string& _return, const int64_t key);
  int32_t send_Get(const int64_t key);
  void recv_Get(std::string& _return, const int32_t seqid);
  void Search(std::vector<int64_t> & _return, const std::string& query);
  int32_t send_Search(const std::string& query);
  void recv_Search(std::vector<int64_t> & _return, const int32_t seqid);
  void Delete(const int64_t key);
  int32_t send_Delete(const int64_t key);
  void recv_Delete(const int32_t seqid);
  int64_t GetNumKeys();
  int32_t send_GetNumKeys();
  int64_t recv_GetNumKeys(const int32_t seqid);
  int64_t GetSize();
  int32_t send_GetSize();
  int64_t recv_GetSize(const int32_t seqid);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _WIN32
  #pragma warning( pop )
#endif

} // namespace

#endif
