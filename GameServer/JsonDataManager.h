#pragma once
#include "pch.h"
#include "TimeUtil.h"
#include "simdjson.h"
#include "LogMacro.h"

class JsonDataManager
{
public:
	void LoadJsonData() {
		TimeUtil::LogElapsedTime(GetFilePath(), [&]() -> void { LoadDataFromPath(); });
	};

private:
	virtual void LoadDataFromPath() abstract;

protected:
	virtual string GetFilePath() abstract;
	void ParseDataFromPath(simdjson::dom::element& data, simdjson::dom::parser& parser) {

		string file_path = GetFilePath();
		auto error = parser.load(file_path).get(data);
		if (error) {
			LOG_ERROR("Failed to parse " + file_path);
			assert(false);
		};
	}
};