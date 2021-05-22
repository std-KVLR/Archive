// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/devtools/device/cast_device_provider.h"

#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include "base/single_thread_task_runner.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/string_split.h"
#include "base/threading/thread_task_runner_handle.h"
#include "chrome/browser/local_discovery/service_discovery_shared_client.h"
#include "net/base/host_port_pair.h"
#include "net/base/ip_address.h"

using local_discovery::ServiceDescription;
using local_discovery::ServiceDiscoveryDeviceLister;
using local_discovery::ServiceDiscoverySharedClient;

namespace {

const int kCastInspectPort = 9222;
const char kCastServiceType[] = "_googlecast._tcp.local";
const char kUnknownCastDevice[] = "Unknown Cast Device";

using ServiceTxtRecordMap = std::map<std::string, std::string>;

// Parses TXT record strings into a map. TXT key-value strings are assumed to
// follow the form "$key(=$value)?", where $key must contain at least one
// character, and $value may be empty.
std::unique_ptr<ServiceTxtRecordMap> ParseServiceTxtRecord(
    const std::vector<std::string>& record) {
  std::unique_ptr<ServiceTxtRecordMap