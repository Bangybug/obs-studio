/****************************************************************************
** Meta object code from reading C++ file 'broadcastwindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "broadcastwindow.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'broadcastwindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BroadcastWindow_t {
    QByteArrayData data[57];
    char stringdata0[729];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BroadcastWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BroadcastWindow_t qt_meta_stringdata_BroadcastWindow = {
    {
QT_MOC_LITERAL(0, 0, 15), // "BroadcastWindow"
QT_MOC_LITERAL(1, 16, 14), // "DeferSaveBegin"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 12), // "DeferSaveEnd"
QT_MOC_LITERAL(4, 45, 14), // "StartStreaming"
QT_MOC_LITERAL(5, 60, 13), // "StopStreaming"
QT_MOC_LITERAL(6, 74, 19), // "StreamDelayStarting"
QT_MOC_LITERAL(7, 94, 3), // "sec"
QT_MOC_LITERAL(8, 98, 19), // "StreamDelayStopping"
QT_MOC_LITERAL(9, 118, 14), // "StreamingStart"
QT_MOC_LITERAL(10, 133, 14), // "StreamStopping"
QT_MOC_LITERAL(11, 148, 13), // "StreamingStop"
QT_MOC_LITERAL(12, 162, 9), // "errorcode"
QT_MOC_LITERAL(13, 172, 10), // "last_error"
QT_MOC_LITERAL(14, 183, 14), // "StartRecording"
QT_MOC_LITERAL(15, 198, 13), // "StopRecording"
QT_MOC_LITERAL(16, 212, 14), // "RecordingStart"
QT_MOC_LITERAL(17, 227, 14), // "RecordStopping"
QT_MOC_LITERAL(18, 242, 13), // "RecordingStop"
QT_MOC_LITERAL(19, 256, 4), // "code"
QT_MOC_LITERAL(20, 261, 17), // "StartReplayBuffer"
QT_MOC_LITERAL(21, 279, 16), // "StopReplayBuffer"
QT_MOC_LITERAL(22, 296, 17), // "ReplayBufferStart"
QT_MOC_LITERAL(23, 314, 16), // "ReplayBufferSave"
QT_MOC_LITERAL(24, 331, 20), // "ReplayBufferStopping"
QT_MOC_LITERAL(25, 352, 16), // "ReplayBufferStop"
QT_MOC_LITERAL(26, 369, 11), // "SaveProject"
QT_MOC_LITERAL(27, 381, 13), // "SetTransition"
QT_MOC_LITERAL(28, 395, 9), // "OBSSource"
QT_MOC_LITERAL(29, 405, 10), // "transition"
QT_MOC_LITERAL(30, 416, 17), // "TransitionToScene"
QT_MOC_LITERAL(31, 434, 8), // "OBSScene"
QT_MOC_LITERAL(32, 443, 5), // "scene"
QT_MOC_LITERAL(33, 449, 5), // "force"
QT_MOC_LITERAL(34, 455, 6), // "direct"
QT_MOC_LITERAL(35, 462, 15), // "quickTransition"
QT_MOC_LITERAL(36, 478, 15), // "SetCurrentScene"
QT_MOC_LITERAL(37, 494, 18), // "AddSceneCollection"
QT_MOC_LITERAL(38, 513, 10), // "create_new"
QT_MOC_LITERAL(39, 524, 4), // "name"
QT_MOC_LITERAL(40, 529, 12), // "ResetOutputs"
QT_MOC_LITERAL(41, 542, 14), // "GetProfilePath"
QT_MOC_LITERAL(42, 557, 5), // "char*"
QT_MOC_LITERAL(43, 563, 4), // "path"
QT_MOC_LITERAL(44, 568, 6), // "size_t"
QT_MOC_LITERAL(45, 575, 4), // "size"
QT_MOC_LITERAL(46, 580, 11), // "const char*"
QT_MOC_LITERAL(47, 592, 4), // "file"
QT_MOC_LITERAL(48, 597, 15), // "InitBasicConfig"
QT_MOC_LITERAL(49, 613, 23), // "InitBasicConfigDefaults"
QT_MOC_LITERAL(50, 637, 10), // "ResetAudio"
QT_MOC_LITERAL(51, 648, 10), // "ResetVideo"
QT_MOC_LITERAL(52, 659, 8), // "AddScene"
QT_MOC_LITERAL(53, 668, 6), // "source"
QT_MOC_LITERAL(54, 675, 11), // "RemoveScene"
QT_MOC_LITERAL(55, 687, 19), // "ActivateAudioSource"
QT_MOC_LITERAL(56, 707, 21) // "DeactivateAudioSource"

    },
    "BroadcastWindow\0DeferSaveBegin\0\0"
    "DeferSaveEnd\0StartStreaming\0StopStreaming\0"
    "StreamDelayStarting\0sec\0StreamDelayStopping\0"
    "StreamingStart\0StreamStopping\0"
    "StreamingStop\0errorcode\0last_error\0"
    "StartRecording\0StopRecording\0"
    "RecordingStart\0RecordStopping\0"
    "RecordingStop\0code\0StartReplayBuffer\0"
    "StopReplayBuffer\0ReplayBufferStart\0"
    "ReplayBufferSave\0ReplayBufferStopping\0"
    "ReplayBufferStop\0SaveProject\0SetTransition\0"
    "OBSSource\0transition\0TransitionToScene\0"
    "OBSScene\0scene\0force\0direct\0quickTransition\0"
    "SetCurrentScene\0AddSceneCollection\0"
    "create_new\0name\0ResetOutputs\0"
    "GetProfilePath\0char*\0path\0size_t\0size\0"
    "const char*\0file\0InitBasicConfig\0"
    "InitBasicConfigDefaults\0ResetAudio\0"
    "ResetVideo\0AddScene\0source\0RemoveScene\0"
    "ActivateAudioSource\0DeactivateAudioSource"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BroadcastWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      44,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  234,    2, 0x0a /* Public */,
       3,    0,  235,    2, 0x0a /* Public */,
       4,    0,  236,    2, 0x0a /* Public */,
       5,    0,  237,    2, 0x0a /* Public */,
       6,    1,  238,    2, 0x0a /* Public */,
       8,    1,  241,    2, 0x0a /* Public */,
       9,    0,  244,    2, 0x0a /* Public */,
      10,    0,  245,    2, 0x0a /* Public */,
      11,    2,  246,    2, 0x0a /* Public */,
      14,    0,  251,    2, 0x0a /* Public */,
      15,    0,  252,    2, 0x0a /* Public */,
      16,    0,  253,    2, 0x0a /* Public */,
      17,    0,  254,    2, 0x0a /* Public */,
      18,    1,  255,    2, 0x0a /* Public */,
      20,    0,  258,    2, 0x0a /* Public */,
      21,    0,  259,    2, 0x0a /* Public */,
      22,    0,  260,    2, 0x0a /* Public */,
      23,    0,  261,    2, 0x0a /* Public */,
      24,    0,  262,    2, 0x0a /* Public */,
      25,    1,  263,    2, 0x0a /* Public */,
      26,    0,  266,    2, 0x0a /* Public */,
      27,    1,  267,    2, 0x0a /* Public */,
      30,    3,  270,    2, 0x0a /* Public */,
      30,    2,  277,    2, 0x2a /* Public | MethodCloned */,
      30,    1,  282,    2, 0x2a /* Public | MethodCloned */,
      30,    4,  285,    2, 0x0a /* Public */,
      30,    3,  294,    2, 0x2a /* Public | MethodCloned */,
      30,    2,  301,    2, 0x2a /* Public | MethodCloned */,
      30,    1,  306,    2, 0x2a /* Public | MethodCloned */,
      36,    3,  309,    2, 0x0a /* Public */,
      36,    2,  316,    2, 0x2a /* Public | MethodCloned */,
      36,    1,  321,    2, 0x2a /* Public | MethodCloned */,
      37,    2,  324,    2, 0x0a /* Public */,
      37,    1,  329,    2, 0x2a /* Public | MethodCloned */,
      40,    0,  332,    2, 0x0a /* Public */,
      41,    3,  333,    2, 0x0a /* Public */,
      48,    0,  340,    2, 0x0a /* Public */,
      49,    0,  341,    2, 0x0a /* Public */,
      50,    0,  342,    2, 0x0a /* Public */,
      51,    0,  343,    2, 0x0a /* Public */,
      52,    1,  344,    2, 0x0a /* Public */,
      54,    1,  347,    2, 0x0a /* Public */,
      55,    1,  350,    2, 0x0a /* Public */,
      56,    1,  353,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 28,   29,
    QMetaType::Void, 0x80000000 | 31, QMetaType::Bool, QMetaType::Bool,   32,   33,   34,
    QMetaType::Void, 0x80000000 | 31, QMetaType::Bool,   32,   33,
    QMetaType::Void, 0x80000000 | 31,   32,
    QMetaType::Void, 0x80000000 | 28, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   32,   33,   34,   35,
    QMetaType::Void, 0x80000000 | 28, QMetaType::Bool, QMetaType::Bool,   32,   33,   34,
    QMetaType::Void, 0x80000000 | 28, QMetaType::Bool,   32,   33,
    QMetaType::Void, 0x80000000 | 28,   32,
    QMetaType::Void, 0x80000000 | 28, QMetaType::Bool, QMetaType::Bool,   32,   33,   34,
    QMetaType::Void, 0x80000000 | 28, QMetaType::Bool,   32,   33,
    QMetaType::Void, 0x80000000 | 28,   32,
    QMetaType::Bool, QMetaType::Bool, QMetaType::QString,   38,   39,
    QMetaType::Bool, QMetaType::Bool,   38,
    QMetaType::Void,
    QMetaType::Int, 0x80000000 | 42, 0x80000000 | 44, 0x80000000 | 46,   43,   45,   47,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Int,
    QMetaType::Void, 0x80000000 | 28,   53,
    QMetaType::Void, 0x80000000 | 28,   53,
    QMetaType::Void, 0x80000000 | 28,   53,
    QMetaType::Void, 0x80000000 | 28,   53,

       0        // eod
};

void BroadcastWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BroadcastWindow *_t = static_cast<BroadcastWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DeferSaveBegin(); break;
        case 1: _t->DeferSaveEnd(); break;
        case 2: _t->StartStreaming(); break;
        case 3: _t->StopStreaming(); break;
        case 4: _t->StreamDelayStarting((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->StreamDelayStopping((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->StreamingStart(); break;
        case 7: _t->StreamStopping(); break;
        case 8: _t->StreamingStop((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->StartRecording(); break;
        case 10: _t->StopRecording(); break;
        case 11: _t->RecordingStart(); break;
        case 12: _t->RecordStopping(); break;
        case 13: _t->RecordingStop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->StartReplayBuffer(); break;
        case 15: _t->StopReplayBuffer(); break;
        case 16: _t->ReplayBufferStart(); break;
        case 17: _t->ReplayBufferSave(); break;
        case 18: _t->ReplayBufferStopping(); break;
        case 19: _t->ReplayBufferStop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->SaveProject(); break;
        case 21: _t->SetTransition((*reinterpret_cast< OBSSource(*)>(_a[1]))); break;
        case 22: _t->TransitionToScene((*reinterpret_cast< OBSScene(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 23: _t->TransitionToScene((*reinterpret_cast< OBSScene(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 24: _t->TransitionToScene((*reinterpret_cast< OBSScene(*)>(_a[1]))); break;
        case 25: _t->TransitionToScene((*reinterpret_cast< OBSSource(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 26: _t->TransitionToScene((*reinterpret_cast< OBSSource(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 27: _t->TransitionToScene((*reinterpret_cast< OBSSource(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 28: _t->TransitionToScene((*reinterpret_cast< OBSSource(*)>(_a[1]))); break;
        case 29: _t->SetCurrentScene((*reinterpret_cast< OBSSource(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 30: _t->SetCurrentScene((*reinterpret_cast< OBSSource(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 31: _t->SetCurrentScene((*reinterpret_cast< OBSSource(*)>(_a[1]))); break;
        case 32: { bool _r = _t->AddSceneCollection((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 33: { bool _r = _t->AddSceneCollection((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 34: _t->ResetOutputs(); break;
        case 35: { int _r = _t->GetProfilePath((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< size_t(*)>(_a[2])),(*reinterpret_cast< const char*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 36: { bool _r = _t->InitBasicConfig();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 37: { bool _r = _t->InitBasicConfigDefaults();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 38: { bool _r = _t->ResetAudio();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 39: { int _r = _t->ResetVideo();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 40: _t->AddScene((*reinterpret_cast< OBSSource(*)>(_a[1]))); break;
        case 41: _t->RemoveScene((*reinterpret_cast< OBSSource(*)>(_a[1]))); break;
        case 42: _t->ActivateAudioSource((*reinterpret_cast< OBSSource(*)>(_a[1]))); break;
        case 43: _t->DeactivateAudioSource((*reinterpret_cast< OBSSource(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject BroadcastWindow::staticMetaObject = {
    { &IMainWindow::staticMetaObject, qt_meta_stringdata_BroadcastWindow.data,
      qt_meta_data_BroadcastWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BroadcastWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BroadcastWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BroadcastWindow.stringdata0))
        return static_cast<void*>(const_cast< BroadcastWindow*>(this));
    return IMainWindow::qt_metacast(_clname);
}

int BroadcastWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 44)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 44;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 44)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 44;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
