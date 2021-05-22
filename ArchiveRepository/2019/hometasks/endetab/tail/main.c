ionUnitImpl* parent : parents_) {
    if (parent == unit || parent->HasParent(unit)) {
      return true;
    }
  }

  return false;
}

bool CoordinationUnitImpl::HasChild(CoordinationUnitImpl* unit) {
  for (CoordinationUnitImpl* child : children_) {
    if (child == unit || child->HasChild(unit)) {
      return true;
    }
  }

  return false;
}

void CoordinationUnitImpl::SetCoordinationPolicyCallback(
    mojom::CoordinationPolicyCallbackPtr callback) {
  callback.set_connection_error_handler(
      base::Bind(&CoordinationUnitImpl::UnregisterCoordinationPolicyCallback,
                 base::Unretained(this)));

  policy_callback_ = std::move(callback);

  RecalcCoordinationPolicy();
}

void CoordinationUnitImpl::UnregisterCoordinationPolicyCallback() {
  policy_callback_.reset();
  current_policy_.reset();
}

std::set<CoordinationUnitImpl*>
CoordinationUnitImpl::GetChildCoordinationUnitsOfType(
    CoordinationUnitType type) {
  std::set<CoordinationUnitImpl*> coordination_units;

  for (auto* child : children()) {
    if (child->id().type == type) {
      coordination_units.insert(child);
    }

    for (auto* coordination_unit :
         child->GetChildCoordinationUnitsOfType(type)) {
      coordination_units.insert(coordination_unit);
    }
  }

  return coordination_units;
}

std::set<CoordinationUnitImpl*>
CoordinationUnitImpl::GetParentCoordinationUnitsOfType(
    CoordinationUnitType type) {
  std::set<CoordinationUnitImpl*> coordination_units;

  for (auto* parent : parents()) {
    if (parent->id().type == type) {
      coordination_units.insert(parent);
    }

    