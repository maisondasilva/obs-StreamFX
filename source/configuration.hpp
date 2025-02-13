/*
 * Modern effects for a modern Streamer
 * Copyright (C) 2020 Michael Fabian Dirks
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#pragma once
#include "common.hpp"

#include "warning-disable.hpp"
#include <filesystem>
#include <memory>
#include "warning-enable.hpp"

namespace streamfx {
	class configuration {
		std::shared_ptr<obs_data_t> _data;

		std::filesystem::path _config_path;

		public:
		~configuration();
		configuration();

		public:
		std::shared_ptr<obs_data_t> get();

		uint64_t version();

		bool is_different_version();

		public /* Singleton */:
		static void                                     initialize();
		static void                                     finalize();
		static std::shared_ptr<streamfx::configuration> instance();
	};
} // namespace streamfx
