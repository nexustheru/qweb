#pragma once
#include <Ultralight/Ultralight.h>
#include <Ultralight/platform/Logger.h>
#include <AppCore/Platform.h>
#include <Ultralight/View.h>
#include <iostream>
#include <string>
#include <memory>
#include <thread>
#include <chrono>
#define EXTERN_DLL_EXPORT extern "C" __declspec(dllexport)
using namespace ultralight;
using namespace std;

class Timer
{
public:
	void start()
	{
		m_StartTime = std::chrono::system_clock::now();
		m_bRunning = true;
	};
	void stop()
	{
		m_EndTime = std::chrono::system_clock::now();
		m_bRunning = false;
	};
	double elapsedMilliseconds()
	{
		std::chrono::time_point<std::chrono::system_clock> endTime;
		if (m_bRunning)
		{
			endTime = std::chrono::system_clock::now();
		}
		else
		{
			endTime = m_EndTime;
		}
		return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - m_StartTime).count();
	}
	double elapsedSeconds()
	{
		return elapsedMilliseconds() / 1000.0;
	}
private:
	std::chrono::time_point<std::chrono::system_clock> m_StartTime;
	std::chrono::time_point<std::chrono::system_clock> m_EndTime;
	bool m_bRunning = false;
};


class ultra : public LoadListener,public Logger
{
public:
	ultra();
	void loadlink(const char* link);
	void start();
	void update();
	void awake();
	bool loaded();
	void takescreenshoot();
	virtual void LogMessage(LogLevel log_level, const String16& message) override;
	virtual void OnFinishLoading(ultralight::View* caller, uint64_t frame_id, bool is_main_frame, const String& url) override;
	~ultra();
private:
	Config* config;
	RefPtr<Renderer> renderer_;
	RefPtr<View> view_;
	bool done_ = false;
	BitmapSurface* bitmap_surface;
	RefPtr<Bitmap> bitmap;
	const char* links;
};

EXTERN_DLL_EXPORT void loadlink(const char* link, ultra* ul);
EXTERN_DLL_EXPORT ultra* ultraInstance();
EXTERN_DLL_EXPORT void update(ultra* ul);
EXTERN_DLL_EXPORT void start(ultra* ul);
EXTERN_DLL_EXPORT bool loaded(ultra* ul);
EXTERN_DLL_EXPORT void takescreenshoot(ultra* ul);
