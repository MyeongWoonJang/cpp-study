#include "dog.h"

int Dog::numid = 0;

const bool operator<(const Dog& lhs, const Dog& rhs) noexcept { return lhs.getid() < rhs.getid(); }
const bool operator>(const Dog& lhs, const Dog& rhs) noexcept { return rhs < lhs; }
const bool operator<=(const Dog& lhs, const Dog& rhs) noexcept { return !(rhs < lhs); }
const bool operator>=(const Dog& lhs, const Dog& rhs) noexcept { return !(lhs < rhs); }
const bool operator==(const Dog& lhs, const Dog& rhs) noexcept { return lhs.getid() == rhs.getid(); }
const bool operator!=(const Dog& lhs, const Dog& rhs) noexcept { return !(lhs == rhs); }