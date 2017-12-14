#include "Rcpp.h"
#include "utils.h"
#include "uv.h"

// [[Rcpp::export]]
std::string realpath_(std::string path) {
  uv_fs_t file_req;
  int res = uv_fs_realpath(uv_default_loop(), &file_req, path.c_str(), NULL);
  stop_for_error(path, res);
  std::string out = reinterpret_cast<const char*>(file_req.ptr);
  uv_fs_req_cleanup(&file_req);
  return out;
}