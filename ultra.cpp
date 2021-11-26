#include "ultra.h"
#include <QtCore/qdir.h>

ultra::ultra()
{
	
}
void ultra::loadlink(const char* link)
{
	cout << "Loading" << endl;
	links = link;
	view_->LoadURL(links);
}
void ultra::takescreenshoot()
{
		
	bitmap_surface = (BitmapSurface*)view_->surface();
	bitmap = bitmap_surface->bitmap();
	bitmap->WritePNG("result.png");
	std::cout << "Finished." << std::endl;
}
void ultra::LogMessage(LogLevel log_level, const String16& message)
{
	std::cout << String(message).utf8().data() << std::endl << std::endl;
}
void ultra::OnFinishLoading(ultralight::View* caller, uint64_t frame_id, bool is_main_frame, const String& url)
{
	if (is_main_frame) 
	{
		std::cout << "Our page has loaded!" << std::endl;
		done_ = true;
	}
}
void ultra::start()
{
	config = new Config();
	config->font_family_standard = "Arial";
	QString pathh = QDir::currentPath() + "/resources";
	config->resource_path = pathh.toStdString().c_str();
	config->device_scale = 2;

	Platform::instance().set_config(*config);
	Platform::instance().set_font_loader(GetPlatformFontLoader());
	Platform::instance().set_file_system(GetPlatformFileSystem("./assets/"));
	Platform::instance().set_logger(this);
	renderer_ = Renderer::Create();

	view_ = renderer_->CreateView(1600, 1600, config, nullptr);
	view_->set_load_listener(this);

}
void ultra::update()
{
		renderer_->Update();
		renderer_->Render();
}
void ultra::awake()
{

}

bool ultra::loaded()
{
	return done_;
}

ultra::~ultra()
{
	view_ = nullptr;
	renderer_ = nullptr;
}

void loadlink(const char* link, ultra* ul)
{
	ul->loadlink(link);
	//ul->loadlink("http://www.google.com");
}
ultra* ultraInstance()
{
	ultra* ul = new ultra();
	return ul;
}
void update(ultra* ul)
{
	ul->update();

}
void start(ultra* ul)
{
	ul->start();
}
void takescreenshoot(ultra* ul)
{
	ul->takescreenshoot();
}
bool loaded(ultra* ul)
{
	return ul->loaded();
}
