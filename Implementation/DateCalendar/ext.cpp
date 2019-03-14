//
//  ext.cpp
//  QuantLib-Example
//
//  Created by Minh Thành Nguyễn on 3/13/19.
//  Copyright © 2019 Minh Thành Nguyễn. All rights reserved.
//

#include "ext.hpp"
#if defined(QL_USE_STD_POINTERS)
#include <memory>
#else

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#endif

namespace QuantLib {

	namespace ext {

#if defined(QL_USE_STD_POINTERS)
		using std::shared_ptr;
		using std::make_shared;
		using std::static_pointer_cast;
		using std::dynamic_pointer_cast;
#else
		using boost::shared_ptr;
		using boost::make_shared;
		using boost::static_pointer_cast;
		using boost::dynamic_pointer_cast;
#endif

	}
	}
