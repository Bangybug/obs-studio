#include "broadcastwindow.hpp"
#include "broadcastwindow.moc.hpp"
#include <qmessagebox.h>
#include <obs-app.hpp>
#include "../../UI/qt-wrappers.hpp"
#include <qscreen.h>
#include <platform.hpp>
#include <volume-control.hpp>
#include <item-widget-helpers.hpp>

extern obs_frontend_callbacks *InitializeAPIInterface(IMainWindow *main);

BroadcastWindow::BroadcastWindow(QWidget *parent)
	: IMainWindow(parent),
	ui(new Ui::BroadcastWindow)
{
	setAttribute(Qt::WA_NativeWindow);

	api = InitializeAPIInterface(this);

	ui->setupUi(this);
}

#define VOLUME_METER_DECAY_FAST        23.53
#define VOLUME_METER_DECAY_MEDIUM      11.76
#define VOLUME_METER_DECAY_SLOW        8.57

static const double scaled_vals[] =
{
	1.0,
	1.25,
	(1.0 / 0.75),
	1.5,
	(1.0 / 0.6),
	1.75,
	2.0,
	2.25,
	2.5,
	2.75,
	3.0,
	0.0
};

static void AddExtraModulePaths()
{
	char base_module_dir[512];
#if defined(_WIN32) || defined(__APPLE__)
	int ret = GetProgramDataPath(base_module_dir, sizeof(base_module_dir),
		"obs-studio/plugins/%module%");
#else
	int ret = GetConfigPath(base_module_dir, sizeof(base_module_dir),
		"obs-studio/plugins/%module%");
#endif

	if (ret <= 0)
		return;

	std::string path = (char*)base_module_dir;
#if defined(__APPLE__)
	obs_add_module_path((path + "/bin").c_str(), (path + "/data").c_str());

	BPtr<char> config_bin = os_get_config_path_ptr("obs-studio/plugins/%module%/bin");
	BPtr<char> config_data = os_get_config_path_ptr("obs-studio/plugins/%module%/data");
	obs_add_module_path(config_bin, config_data);

#elif ARCH_BITS == 64
	obs_add_module_path((path + "/bin/64bit").c_str(),
		(path + "/data").c_str());
#else
	obs_add_module_path((path + "/bin/32bit").c_str(),
		(path + "/data").c_str());
#endif
}

void BroadcastWindow::OBSInit()
{
	const char *sceneCollection = config_get_string(App()->GlobalConfig(),
		"Basic", "SceneCollectionFile");
	char savePath[512];
	char fileName[512];
	int ret;

	if (!sceneCollection)
		throw "Failed to get scene collection name";

	ret = snprintf(fileName, 512, "obs-studio/basic/scenes/%s.json",
		sceneCollection);
	if (ret <= 0)
		throw "Failed to create scene collection file name";

	ret = GetConfigPath(savePath, sizeof(savePath), fileName);
	if (ret <= 0)
		throw "Failed to get scene collection json file path";

	if (!InitBasicConfig())
		throw "Failed to load basic.ini";

	if (!ResetAudio())
		throw "Failed to initialize audio";

	/* load audio monitoring */
#if defined(_WIN32) || defined(__APPLE__) || HAVE_PULSEAUDIO
	const char *device_name = config_get_string(basicConfig, "Audio",
		"MonitoringDeviceName");
	const char *device_id = config_get_string(basicConfig, "Audio",
		"MonitoringDeviceId");

	obs_set_audio_monitoring_device(device_name, device_id);

	blog(LOG_INFO, "Audio monitoring device:\n\tname: %s\n\tid: %s",
		device_name, device_id);
#endif

	InitOBSCallbacks();
//	InitHotkeys();

	AddExtraModulePaths();
	blog(LOG_INFO, "---------------------------------");
	obs_load_all_modules();
	blog(LOG_INFO, "---------------------------------");
	obs_log_loaded_modules();
	blog(LOG_INFO, "---------------------------------");
	obs_post_load_modules();

#if defined(_WIN32) && defined(BROWSER_AVAILABLE)
	create_browser_widget = obs_browser_init_panel();
#endif

	ResetOutputs();
}

int BroadcastWindow::getSceneCount()
{
//  main->ui->scenes->count()
	return 0;
}

OBSScene BroadcastWindow::getScene(int index)
{
/*
QListWidgetItem *item = main->ui->scenes->item(i);
OBSScene scene = GetOBSRef<OBSScene>(item);
*/
	return NULL;
}


OBSWeakSource BroadcastWindow::getProgramScene()
{
	return programScene;
}

OBSSource BroadcastWindow::GetCurrentSceneSource()
{
	OBSScene curScene = GetCurrentScene();
	return OBSSource(obs_scene_get_source(curScene));
}

OBSScene BroadcastWindow::GetCurrentScene()
{
	//QListWidgetItem *item = ui->scenes->currentItem();
	//return item ? GetOBSRef<OBSScene>(item) : nullptr;
	return nullptr;
}

int BroadcastWindow::getTransitionCount()
{
	return 0;
}

OBSSource BroadcastWindow::getTransition(int index)
{
//	OBSSource tr = main->ui->transitions->itemData(i).value<OBSSource>();
	return nullptr;
}


OBSSource BroadcastWindow::GetCurrentTransition()
{
//TODO 
	return nullptr;
}



void BroadcastWindow::openSceneCollection(const char* collection)
{
/*
	QList<QAction*> menuActions =
		main->ui->sceneCollectionMenu->actions();
	QString qstrCollection = QT_UTF8(collection);

	for (int i = 0; i < menuActions.count(); i++) {
		QAction *action = menuActions[i];
		QVariant v = action->property("file_name");

		if (v.typeName() != nullptr) {
			if (action->text() == qstrCollection) {
				action->trigger();
				break;
			}
		}
	}
*/
}


void BroadcastWindow::setCurrentProfile(const char* profile)
{
/*
	QList<QAction*> menuActions =
		main->ui->profileMenu->actions();
	QString qstrProfile = QT_UTF8(profile);

	for (int i = 0; i < menuActions.count(); i++) {
		QAction *action = menuActions[i];
		QVariant v = action->property("file_name");

		if (v.typeName() != nullptr) {
			if (action->text() == qstrProfile) {
				action->trigger();
				break;
			}
		}
	}
*/
}


bool BroadcastWindow::isStreamingActive()
{
// return main->outputHandler->StreamingActive();
	return false;
}



bool BroadcastWindow::isRecordingActive()
{
// return main->outputHandler->RecordingActive();
	return false;
}



bool BroadcastWindow::isReplayBufferActive()
{
// return main->outputHandler->ReplayBufferActive();
	return false;
}


void* BroadcastWindow::addToolsMenuAction(const char *name)
{
//	main->ui->menuTools->setEnabled(true);
//	return (void*)main->ui->menuTools->addAction(QT_UTF8(name));
	return nullptr;
}


void BroadcastWindow::addToolsMenuItem(const char *name, obs_frontend_cb callback, void *private_data)
{
/*
main->ui->menuTools->setEnabled(true);

auto func = [private_data, callback] ()
{
callback(private_data);
};

QAction *action = main->ui->menuTools->addAction(QT_UTF8(name));
QObject::connect(action, &QAction::triggered, func);
*/

}


std::unique_ptr<BasicOutputHandler>& BroadcastWindow::getOutputHandler()
{
	return outputHandler;
}

config_t *BroadcastWindow::getProfileConfig()
{
	return basicConfig;
}


void BroadcastWindow::SetService(obs_service_t *newService)
{
	if (newService)
		service = newService;
}

obs_service_t *BroadcastWindow::GetService()
{
	if (!service) {
		service = obs_service_create("rtmp_common", NULL, NULL,
			nullptr);
		obs_service_release(service);
	}
	return service;
}

void BroadcastWindow::SaveService()
{
/*
	if (!service)
		return;

	char serviceJsonPath[512];
	int ret = GetProfilePath(serviceJsonPath, sizeof(serviceJsonPath),
		SERVICE_PATH);
	if (ret <= 0)
		return;

	obs_data_t *data = obs_data_create();
	obs_data_t *settings = obs_service_get_settings(service);

	obs_data_set_string(data, "type", obs_service_get_type(service));
	obs_data_set_obj(data, "settings", settings);

	if (!obs_data_save_json_safe(data, serviceJsonPath, "tmp", "bak"))
		blog(LOG_WARNING, "Failed to save service");

	obs_data_release(settings);
	obs_data_release(data);
*/
}


void BroadcastWindow::SetPreviewProgramMode(bool enabled)
{
	// TODO
}


bool BroadcastWindow::isPreviewEnabled()
{
	return previewEnabled;
}

void BroadcastWindow::EnablePreviewDisplay(bool enabled)
{
	previewEnabled = enabled;
	/*
	obs_display_set_enabled(ui->preview->GetDisplay(), enable);
	ui->preview->setVisible(enable);
	ui->previewDisabledLabel->setVisible(!enable);
	*/
}

OBSSource BroadcastWindow::GetProgramSource()
{
	return nullptr;
}


float BroadcastWindow::getPreviewScale()
{
	return previewScale;
}


SPreviewInfo& BroadcastWindow::getPreviewInfo()
{
	return previewInfo;
}

config_t *BroadcastWindow::Config() const
{
	return basicConfig;
}

void BroadcastWindow::SysTrayNotify(const QString &text, QSystemTrayIcon::MessageIcon n)
{
}


void BroadcastWindow::DeferSaveBegin()
{
	os_atomic_inc_long(&disableSaving);
}


void BroadcastWindow::DeferSaveEnd()
{
	long result = os_atomic_dec_long(&disableSaving);
	if (result == 0) {
		SaveProject();
	}
}


void BroadcastWindow::StartStreaming()
{
	if (outputHandler->StreamingActive())
		return;
	if (disableOutputsRef)
		return;

	if (api)
		api->on_event(OBS_FRONTEND_EVENT_STREAMING_STARTING);

	SaveProject();
	
	// ui->streamButton->setEnabled(false);
	// ui->streamButton->setText(QTStr("Basic.Main.Connecting"));

	if (!outputHandler->StartStreaming(service))
	{
	/*
		ui->streamButton->setText(QTStr("Basic.Main.StartStreaming"));
		ui->streamButton->setEnabled(true);
		ui->streamButton->setChecked(false);
	*/

		QMessageBox::critical(this,
			QTStr("Output.StartStreamFailed"),
			QTStr("Output.StartFailedGeneric"));
		return;
	}

	bool recordWhenStreaming = config_get_bool(GetGlobalConfig(),
		"BasicWindow", "RecordWhenStreaming");
	if (recordWhenStreaming)
		StartRecording();

	bool replayBufferWhileStreaming = config_get_bool(GetGlobalConfig(),
		"BasicWindow", "ReplayBufferWhileStreaming");
	if (replayBufferWhileStreaming)
		StartReplayBuffer();
}

void BroadcastWindow::StopStreaming()
{
}

void BroadcastWindow::StreamDelayStarting(int sec)
{
}

void BroadcastWindow::StreamDelayStopping(int sec)
{
}

void BroadcastWindow::StreamingStart()
{
}

void BroadcastWindow::StreamStopping()
{
}

void BroadcastWindow::StreamingStop(int errorcode, QString last_error)
{
}

void BroadcastWindow::StartRecording()
{
}

void BroadcastWindow::StopRecording()
{
}

void BroadcastWindow::RecordingStart()
{
}

void BroadcastWindow::RecordStopping()
{
}

void BroadcastWindow::RecordingStop(int code)
{
}

void BroadcastWindow::StartReplayBuffer()
{
}

void BroadcastWindow::StopReplayBuffer()
{
}

void BroadcastWindow::ReplayBufferStart()
{
}

void BroadcastWindow::ReplayBufferSave()
{
}

void BroadcastWindow::ReplayBufferStopping()
{
}

void BroadcastWindow::ReplayBufferStop(int code)
{
}

void BroadcastWindow::SaveProject()
{
}

void BroadcastWindow::SetTransition(OBSSource transition)
{
}

void BroadcastWindow::TransitionToScene(OBSScene scene, bool force, bool direct)
{
}

void BroadcastWindow::TransitionToScene(OBSSource scene, bool force, bool direct, bool quickTransition)
{
}

void BroadcastWindow::SetCurrentScene(OBSSource scene, bool force, bool direct)
{
}

bool BroadcastWindow::AddSceneCollection(
	bool create_new,
	const QString &name)
{
	return true;
}


void BroadcastWindow::ResetOutputs()
{
	const char *mode = config_get_string(basicConfig, "Output", "Mode");
	bool advOut = astrcmpi(mode, "Advanced") == 0;

	if (!outputHandler || !outputHandler->Active()) {
		outputHandler.reset();
		outputHandler.reset(advOut ?
			CreateAdvancedOutputHandler(this) :
			CreateSimpleOutputHandler(this));
	}
	else {
		outputHandler->Update();
	}
}


int BroadcastWindow::GetProfilePath(char *path, size_t size, const char *file) const
{
	char profiles_path[512];
	const char *profile = config_get_string(App()->GlobalConfig(),
		"Basic", "ProfileDir");
	int ret;

	if (!profile)
		return -1;
	if (!path)
		return -1;
	if (!file)
		file = "";

	ret = GetConfigPath(profiles_path, 512, "obs-studio/basic/profiles");
	if (ret <= 0)
		return ret;

	if (!*file)
		return snprintf(path, size, "%s/%s", profiles_path, profile);

	return snprintf(path, size, "%s/%s/%s", profiles_path, profile, file);
}


bool BroadcastWindow::InitBasicConfig()
{
	char configPath[512];

	int ret = GetProfilePath(configPath, sizeof(configPath), "");
	if (ret <= 0) {
		OBSErrorBox(nullptr, "Failed to get profile path");
		return false;
	}

	if (os_mkdir(configPath) == MKDIR_ERROR) {
		OBSErrorBox(nullptr, "Failed to create profile path");
		return false;
	}

	ret = GetProfilePath(configPath, sizeof(configPath), "basic.ini");
	if (ret <= 0) {
		OBSErrorBox(nullptr, "Failed to get base.ini path");
		return false;
	}

	int code = basicConfig.Open(configPath, CONFIG_OPEN_ALWAYS);
	if (code != CONFIG_SUCCESS) {
		OBSErrorBox(NULL, "Failed to open basic.ini: %d", code);
		return false;
	}

	if (config_get_string(basicConfig, "General", "Name") == nullptr) {
		const char *curName = config_get_string(App()->GlobalConfig(),
			"Basic", "Profile");

		config_set_string(basicConfig, "General", "Name", curName);
		basicConfig.SaveSafe("tmp");
	}

	return InitBasicConfigDefaults();
}


bool BroadcastWindow::InitBasicConfigDefaults()
{
	QList<QScreen*> screens = QGuiApplication::screens();

	if (!screens.size()) {
		OBSErrorBox(NULL, "There appears to be no monitors.  Er, this "
			"technically shouldn't be possible.");
		return false;
	}

	QScreen *primaryScreen = QGuiApplication::primaryScreen();

	uint32_t cx = primaryScreen->size().width();
	uint32_t cy = primaryScreen->size().height();

	bool oldResolutionDefaults = config_get_bool(App()->GlobalConfig(),
		"General", "Pre19Defaults");

	/* use 1920x1080 for new default base res if main monitor is above
	* 1920x1080, but don't apply for people from older builds -- only to
	* new users */
	if (!oldResolutionDefaults && (cx * cy) > (1920 * 1080)) {
		cx = 1920;
		cy = 1080;
	}

	/* ----------------------------------------------------- */
	/* move over mixer values in advanced if older config */
	if (config_has_user_value(basicConfig, "AdvOut", "RecTrackIndex") &&
		!config_has_user_value(basicConfig, "AdvOut", "RecTracks")) {

		uint64_t track = config_get_uint(basicConfig, "AdvOut",
			"RecTrackIndex");
		track = 1ULL << (track - 1);
		config_set_uint(basicConfig, "AdvOut", "RecTracks", track);
		config_remove_value(basicConfig, "AdvOut", "RecTrackIndex");
		config_save_safe(basicConfig, "tmp", nullptr);
	}

	/* ----------------------------------------------------- */

	config_set_default_string(basicConfig, "Output", "Mode", "Simple");

	config_set_default_string(basicConfig, "SimpleOutput", "FilePath",
		GetDefaultVideoSavePath().c_str());
	config_set_default_string(basicConfig, "SimpleOutput", "RecFormat",
		"flv");
	config_set_default_uint(basicConfig, "SimpleOutput", "VBitrate",
		2500);
	config_set_default_string(basicConfig, "SimpleOutput", "StreamEncoder",
		SIMPLE_ENCODER_X264);
	config_set_default_uint(basicConfig, "SimpleOutput", "ABitrate", 160);
	config_set_default_bool(basicConfig, "SimpleOutput", "UseAdvanced",
		false);
	config_set_default_bool(basicConfig, "SimpleOutput", "EnforceBitrate",
		true);
	config_set_default_string(basicConfig, "SimpleOutput", "Preset",
		"veryfast");
	config_set_default_string(basicConfig, "SimpleOutput", "RecQuality",
		"Stream");
	config_set_default_string(basicConfig, "SimpleOutput", "RecEncoder",
		SIMPLE_ENCODER_X264);
	config_set_default_bool(basicConfig, "SimpleOutput", "RecRB", false);
	config_set_default_int(basicConfig, "SimpleOutput", "RecRBTime", 20);
	config_set_default_int(basicConfig, "SimpleOutput", "RecRBSize", 512);
	config_set_default_string(basicConfig, "SimpleOutput", "RecRBPrefix",
		"Replay");

	config_set_default_bool(basicConfig, "AdvOut", "ApplyServiceSettings",
		true);
	config_set_default_bool(basicConfig, "AdvOut", "UseRescale", false);
	config_set_default_uint(basicConfig, "AdvOut", "TrackIndex", 1);
	config_set_default_string(basicConfig, "AdvOut", "Encoder", "obs_x264");

	config_set_default_string(basicConfig, "AdvOut", "RecType", "Standard");

	config_set_default_string(basicConfig, "AdvOut", "RecFilePath",
		GetDefaultVideoSavePath().c_str());
	config_set_default_string(basicConfig, "AdvOut", "RecFormat", "flv");
	config_set_default_bool(basicConfig, "AdvOut", "RecUseRescale",
		false);
	config_set_default_uint(basicConfig, "AdvOut", "RecTracks", (1 << 0));
	config_set_default_string(basicConfig, "AdvOut", "RecEncoder",
		"none");

	config_set_default_bool(basicConfig, "AdvOut", "FFOutputToFile",
		true);
	config_set_default_string(basicConfig, "AdvOut", "FFFilePath",
		GetDefaultVideoSavePath().c_str());
	config_set_default_string(basicConfig, "AdvOut", "FFExtension", "mp4");
	config_set_default_uint(basicConfig, "AdvOut", "FFVBitrate", 2500);
	config_set_default_uint(basicConfig, "AdvOut", "FFVGOPSize", 250);
	config_set_default_bool(basicConfig, "AdvOut", "FFUseRescale",
		false);
	config_set_default_bool(basicConfig, "AdvOut", "FFIgnoreCompat",
		false);
	config_set_default_uint(basicConfig, "AdvOut", "FFABitrate", 160);
	config_set_default_uint(basicConfig, "AdvOut", "FFAudioTrack", 1);

	config_set_default_uint(basicConfig, "AdvOut", "Track1Bitrate", 160);
	config_set_default_uint(basicConfig, "AdvOut", "Track2Bitrate", 160);
	config_set_default_uint(basicConfig, "AdvOut", "Track3Bitrate", 160);
	config_set_default_uint(basicConfig, "AdvOut", "Track4Bitrate", 160);
	config_set_default_uint(basicConfig, "AdvOut", "Track5Bitrate", 160);
	config_set_default_uint(basicConfig, "AdvOut", "Track6Bitrate", 160);

	config_set_default_bool(basicConfig, "AdvOut", "RecRB", false);
	config_set_default_uint(basicConfig, "AdvOut", "RecRBTime", 20);
	config_set_default_int(basicConfig, "AdvOut", "RecRBSize", 512);

	config_set_default_uint(basicConfig, "Video", "BaseCX", cx);
	config_set_default_uint(basicConfig, "Video", "BaseCY", cy);

	/* don't allow BaseCX/BaseCY to be susceptible to defaults changing */
	if (!config_has_user_value(basicConfig, "Video", "BaseCX") ||
		!config_has_user_value(basicConfig, "Video", "BaseCY")) {
		config_set_uint(basicConfig, "Video", "BaseCX", cx);
		config_set_uint(basicConfig, "Video", "BaseCY", cy);
		config_save_safe(basicConfig, "tmp", nullptr);
	}

	config_set_default_string(basicConfig, "Output", "FilenameFormatting",
		"%CCYY-%MM-%DD %hh-%mm-%ss");

	config_set_default_bool(basicConfig, "Output", "DelayEnable", false);
	config_set_default_uint(basicConfig, "Output", "DelaySec", 20);
	config_set_default_bool(basicConfig, "Output", "DelayPreserve", true);

	config_set_default_bool(basicConfig, "Output", "Reconnect", true);
	config_set_default_uint(basicConfig, "Output", "RetryDelay", 10);
	config_set_default_uint(basicConfig, "Output", "MaxRetries", 20);

	config_set_default_string(basicConfig, "Output", "BindIP", "default");
	config_set_default_bool(basicConfig, "Output", "NewSocketLoopEnable",
		false);
	config_set_default_bool(basicConfig, "Output", "LowLatencyEnable",
		false);

	int i = 0;
	uint32_t scale_cx = cx;
	uint32_t scale_cy = cy;

	/* use a default scaled resolution that has a pixel count no higher
	* than 1280x720 */
	while (((scale_cx * scale_cy) > (1280 * 720)) && scaled_vals[i] > 0.0) {
		double scale = scaled_vals[i++];
		scale_cx = uint32_t(double(cx) / scale);
		scale_cy = uint32_t(double(cy) / scale);
	}

	config_set_default_uint(basicConfig, "Video", "OutputCX", scale_cx);
	config_set_default_uint(basicConfig, "Video", "OutputCY", scale_cy);

	/* don't allow OutputCX/OutputCY to be susceptible to defaults
	* changing */
	if (!config_has_user_value(basicConfig, "Video", "OutputCX") ||
		!config_has_user_value(basicConfig, "Video", "OutputCY")) {
		config_set_uint(basicConfig, "Video", "OutputCX", scale_cx);
		config_set_uint(basicConfig, "Video", "OutputCY", scale_cy);
		config_save_safe(basicConfig, "tmp", nullptr);
	}

	config_set_default_uint(basicConfig, "Video", "FPSType", 0);
	config_set_default_string(basicConfig, "Video", "FPSCommon", "30");
	config_set_default_uint(basicConfig, "Video", "FPSInt", 30);
	config_set_default_uint(basicConfig, "Video", "FPSNum", 30);
	config_set_default_uint(basicConfig, "Video", "FPSDen", 1);
	config_set_default_string(basicConfig, "Video", "ScaleType", "bicubic");
	config_set_default_string(basicConfig, "Video", "ColorFormat", "NV12");
	config_set_default_string(basicConfig, "Video", "ColorSpace", "601");
	config_set_default_string(basicConfig, "Video", "ColorRange",
		"Partial");

	config_set_default_string(basicConfig, "Audio", "MonitoringDeviceId",
		"default");
	config_set_default_string(basicConfig, "Audio", "MonitoringDeviceName",
		Str("Basic.Settings.Advanced.Audio.MonitoringDevice"
			".Default"));
	config_set_default_uint(basicConfig, "Audio", "SampleRate", 44100);
	config_set_default_string(basicConfig, "Audio", "ChannelSetup",
		"Stereo");
	config_set_default_double(basicConfig, "Audio", "MeterDecayRate",
		VOLUME_METER_DECAY_FAST);
	config_set_default_uint(basicConfig, "Audio", "PeakMeterType", 0);

	return true;
}



bool BroadcastWindow::ResetAudio()
{
	struct obs_audio_info ai;
	ai.samples_per_sec = config_get_uint(basicConfig, "Audio",
		"SampleRate");

	const char *channelSetupStr = config_get_string(basicConfig,
		"Audio", "ChannelSetup");

	if (strcmp(channelSetupStr, "Mono") == 0)
		ai.speakers = SPEAKERS_MONO;
	else if (strcmp(channelSetupStr, "2.1") == 0)
		ai.speakers = SPEAKERS_2POINT1;
	else if (strcmp(channelSetupStr, "4.0") == 0)
		ai.speakers = SPEAKERS_4POINT0;
	else if (strcmp(channelSetupStr, "4.1") == 0)
		ai.speakers = SPEAKERS_4POINT1;
	else if (strcmp(channelSetupStr, "5.1") == 0)
		ai.speakers = SPEAKERS_5POINT1;
	else if (strcmp(channelSetupStr, "7.1") == 0)
		ai.speakers = SPEAKERS_7POINT1;
	else
		ai.speakers = SPEAKERS_STEREO;

	return obs_reset_audio(&ai);
}



void BroadcastWindow::SourceCreated(void *data, calldata_t *params)
{
	obs_source_t *source = (obs_source_t*)calldata_ptr(params, "source");

	if (obs_scene_from_source(source) != NULL)
		QMetaObject::invokeMethod(static_cast<BroadcastWindow*>(data),
			"AddScene", WaitConnection(),
			Q_ARG(OBSSource, OBSSource(source)));
}

void BroadcastWindow::SourceRemoved(void *data, calldata_t *params)
{
	obs_source_t *source = (obs_source_t*)calldata_ptr(params, "source");

	if (obs_scene_from_source(source) != NULL)
		QMetaObject::invokeMethod(static_cast<BroadcastWindow*>(data),
			"RemoveScene",
			Q_ARG(OBSSource, OBSSource(source)));
}

void BroadcastWindow::SourceActivated(void *data, calldata_t *params)
{
	obs_source_t *source = (obs_source_t*)calldata_ptr(params, "source");
	uint32_t     flags = obs_source_get_output_flags(source);

	if (flags & OBS_SOURCE_AUDIO)
		QMetaObject::invokeMethod(static_cast<BroadcastWindow*>(data),
			"ActivateAudioSource",
			Q_ARG(OBSSource, OBSSource(source)));
}

void BroadcastWindow::SourceDeactivated(void *data, calldata_t *params)
{
	obs_source_t *source = (obs_source_t*)calldata_ptr(params, "source");
	uint32_t     flags = obs_source_get_output_flags(source);

	if (flags & OBS_SOURCE_AUDIO)
		QMetaObject::invokeMethod(static_cast<BroadcastWindow*>(data),
			"DeactivateAudioSource",
			Q_ARG(OBSSource, OBSSource(source)));
}


void BroadcastWindow::AddScene(OBSSource source)
{
}

void BroadcastWindow::RemoveScene(OBSSource source)
{
}

void BroadcastWindow::ActivateAudioSource(OBSSource source)
{
	bool vertical = false;
	VolControl *vol = new VolControl(source, true, vertical);

	double meterDecayRate = config_get_double(basicConfig, "Audio",
		"MeterDecayRate");
	vol->SetMeterDecayRate(meterDecayRate);

	uint32_t peakMeterTypeIdx = config_get_uint(basicConfig, "Audio",
		"PeakMeterType");

	enum obs_peak_meter_type peakMeterType;
	switch (peakMeterTypeIdx) {
	case 0:
		peakMeterType = SAMPLE_PEAK_METER;
		break;
	case 1:
		peakMeterType = TRUE_PEAK_METER;
		break;
	default:
		peakMeterType = SAMPLE_PEAK_METER;
		break;
	}

	vol->setPeakMeterType(peakMeterType);
/*
	vol->setContextMenuPolicy(Qt::CustomContextMenu);

	connect(vol, &QWidget::customContextMenuRequested,
		this, &OBSBasic::VolControlContextMenu);
	connect(vol, &VolControl::ConfigClicked,
		this, &OBSBasic::VolControlContextMenu);
*/
	InsertQObjectByName(volumes, vol);

	for (auto volume : volumes) {
		ui->previewPane->ui->hVolControlLayout->addWidget(volume);
	}
}

void BroadcastWindow::DeactivateAudioSource(OBSSource source)
{
	for (size_t i = 0; i < volumes.size(); i++) {
		if (volumes[i]->GetSource() == source) {
			delete volumes[i];
			volumes.erase(volumes.begin() + i);
			break;
		}
	}
}


void BroadcastWindow::InitOBSCallbacks()
{
	signalHandlers.reserve(signalHandlers.size() + 6);
	signalHandlers.emplace_back(obs_get_signal_handler(), "source_create",
		BroadcastWindow::SourceCreated, this);
	signalHandlers.emplace_back(obs_get_signal_handler(), "source_remove",
		BroadcastWindow::SourceRemoved, this);
	signalHandlers.emplace_back(obs_get_signal_handler(), "source_activate",
		BroadcastWindow::SourceActivated, this);
	signalHandlers.emplace_back(obs_get_signal_handler(), "source_deactivate",
		BroadcastWindow::SourceDeactivated, this);
//	signalHandlers.emplace_back(obs_get_signal_handler(), "source_rename",
//		BroadcastWindow::SourceRenamed, this);
}
