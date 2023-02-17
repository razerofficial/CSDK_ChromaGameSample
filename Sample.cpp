﻿// Sample.cpp : Defines the entry point for the console application.
//

#include <chrono>
#include <iostream>
#include <tchar.h>

#include "HandleInput.h"
#include "CpuUsage.h"
#include "Razer\ChromaSDKPluginTypes.h"
#include "Razer\ChromaAnimationAPI.h"
#include "RazerKeyboardMapping.h"

using namespace std;
using namespace std::chrono;
using namespace ChromaSDK;

const float MATH_PI = 3.14159f;

#pragma region Autogenerated
void ShowEffect1()
{
}
void ShowEffect1ChromaLink()
{
}
void ShowEffect1Headset()
{
}
void ShowEffect1Mousepad()
{
}
void ShowEffect1Mouse()
{
}
void ShowEffect1Keypad()
{
}
void ShowEffect2()
{
}
void ShowEffect2ChromaLink()
{
}
void ShowEffect2Headset()
{
}
void ShowEffect2Mousepad()
{
}
void ShowEffect2Mouse()
{
}
void ShowEffect2Keypad()
{
}
void ShowEffect3()
{
}
void ShowEffect3ChromaLink()
{
}
void ShowEffect3Headset()
{
}
void ShowEffect3Mousepad()
{
}
void ShowEffect3Mouse()
{
}
void ShowEffect3Keypad()
{
}
void ShowEffect4()
{
}
void ShowEffect4ChromaLink()
{
}
void ShowEffect4Headset()
{
}
void ShowEffect4Mousepad()
{
}
void ShowEffect4Mouse()
{
}
void ShowEffect4Keypad()
{
}
void ShowEffect5()
{
}
void ShowEffect5ChromaLink()
{
}
void ShowEffect5Headset()
{
}
void ShowEffect5Mousepad()
{
}
void ShowEffect5Mouse()
{
}
void ShowEffect5Keypad()
{
}
void ShowEffect6()
{
}
void ShowEffect6ChromaLink()
{
}
void ShowEffect6Headset()
{
}
void ShowEffect6Mousepad()
{
}
void ShowEffect6Mouse()
{
}
void ShowEffect6Keypad()
{
}
void ShowEffect7()
{
}
void ShowEffect7ChromaLink()
{
}
void ShowEffect7Headset()
{
}
void ShowEffect7Mousepad()
{
}
void ShowEffect7Mouse()
{
}
void ShowEffect7Keypad()
{
}
void ShowEffect8()
{
}
void ShowEffect8ChromaLink()
{
}
void ShowEffect8Headset()
{
}
void ShowEffect8Mousepad()
{
}
void ShowEffect8Mouse()
{
}
void ShowEffect8Keypad()
{
}
void ShowEffect9()
{
}
void ShowEffect9ChromaLink()
{
}
void ShowEffect9Headset()
{
}
void ShowEffect9Mousepad()
{
}
void ShowEffect9Mouse()
{
}
void ShowEffect9Keypad()
{
}
void ShowEffect10()
{
}
void ShowEffect10ChromaLink()
{
}
void ShowEffect10Headset()
{
}
void ShowEffect10Mousepad()
{
}
void ShowEffect10Mouse()
{
}
void ShowEffect10Keypad()
{
}
void ShowEffect11()
{
}
void ShowEffect11ChromaLink()
{
}
void ShowEffect11Headset()
{
}
void ShowEffect11Mousepad()
{
}
void ShowEffect11Mouse()
{
}
void ShowEffect11Keypad()
{
}
void ShowEffect12()
{
}
void ShowEffect12ChromaLink()
{
}
void ShowEffect12Headset()
{
}
void ShowEffect12Mousepad()
{
}
void ShowEffect12Mouse()
{
}
void ShowEffect12Keypad()
{
}
void ShowEffect13()
{
}
void ShowEffect13ChromaLink()
{
}
void ShowEffect13Headset()
{
}
void ShowEffect13Mousepad()
{
}
void ShowEffect13Mouse()
{
}
void ShowEffect13Keypad()
{
}
void ShowEffect14()
{
}
void ShowEffect14ChromaLink()
{
}
void ShowEffect14Headset()
{
}
void ShowEffect14Mousepad()
{
}
void ShowEffect14Mouse()
{
}
void ShowEffect14Keypad()
{
}
void ShowEffect15()
{
}
void ShowEffect15ChromaLink()
{
}
void ShowEffect15Headset()
{
}
void ShowEffect15Mousepad()
{
}
void ShowEffect15Mouse()
{
}
void ShowEffect15Keypad()
{
}
#pragma endregion


int _gSelection = 1;
const int MAX_SELECTION = 15;
int _gIndex = 0;
char _gTextBuffer[16];
char _gManualInput[] = {
	' ',
	' ',
};

char _gShortcode[7] = { 0 };
char _gStreamId[48] = { 0 };
char _gStreamKey[48] = { 0 };
unsigned char _gLenShortcode = 0;
unsigned char _gLenStreamId = 0;
unsigned char _gLenStreamKey = 0;

const char* g_FocusGuid = "UnitTest";
char g_Focus[48] = { 0 };
unsigned char g_LenFocus = 0;

const char* IsSelected()
{
	++_gIndex;
	if (_gIndex == _gSelection)
	{
		return "*";
	}
	else
	{
        if (_gIndex <= 0)
        {
            return " ";
        }
		memset(_gTextBuffer, 0, size(_gTextBuffer));
		sprintf_s(_gTextBuffer, "%d", _gIndex);
		return _gTextBuffer;
	}
}

CpuUsage _gUsage;

void PrintLegend(bool supportsStreaming, BYTE platform)
{
	for (int i = 0; i < 25; ++i)
	{
		fprintf(stdout, "\r\n");
	}

	fprintf(stdout, "C++ CHROMA GAME SAMPLE APP\r\n");
	fprintf(stdout, "\r\n");

	fprintf(stdout, "Use UP and DOWN arrows to select animation and press ENTER.\r\n");
	if (supportsStreaming)
	{
		fprintf(stdout, "Use `P` to switch streaming platforms. ");
	}
    fprintf(stdout, "Use ESCAPE to QUIT.\r\n");

    if (supportsStreaming)
    {
        fprintf(stdout, "Streaming Info (SUPPORTED):\r\n");
		ChromaSDK::Stream::StreamStatusType status = ChromaAnimationAPI::CoreStreamGetStatus();
		fprintf(stdout, "Status: %s\r\n", ChromaAnimationAPI::CoreStreamGetStatusString(status));
        if (_gLenShortcode > 0)
        {
            fprintf(stdout, "Shortcode: %s\r\n", _gShortcode);
        }
        if (_gLenStreamId > 0)
        {
            fprintf(stdout, "StreamId: %s\r\n", _gStreamId);
        }
        if (_gLenStreamKey > 0)
        {
            fprintf(stdout, "StreamKey: %s\r\n", _gStreamKey);
        }
        if (g_LenFocus > 0)
        {
            fprintf(stdout, "Focus: %s\r\n", g_Focus);
        }

        short cpuUsage = _gUsage.GetUsage();
        cout << "CPU usage: " << cpuUsage << "%" << endl;

        fprintf(stdout, "\r\n");
    }
    

    if (supportsStreaming)
    {
        _gIndex = -10;
		fprintf(stdout, "[%s] Request Shortcode for Platform: ", IsSelected());

		switch (platform)
		{
		case 0:
			fprintf(stdout, "Windows PC (PC)\r\n");
			break;
		case 1:
			fprintf(stdout, "Windows Cloud (LUNA)\r\n");
			break;
		case 2:
			fprintf(stdout, "Windows Cloud (GEFORCE NOW)\r\n");
			break;
		case 3:
			fprintf(stdout, "Windows Cloud (GAME PASS)\r\n");
			break;
		}

        fprintf(stdout, "[%s] Request StreamId\r\n", IsSelected());
        fprintf(stdout, "[%s] Request StreamKey\r\n", IsSelected());
        fprintf(stdout, "[%s] Release Shortcode\r\n", IsSelected());
        fprintf(stdout, "[%s] Broadcast\t\t", IsSelected());
        fprintf(stdout, "[%s] BroadcastEnd\r\n", IsSelected());
        fprintf(stdout, "[%s] Watch\t\t", IsSelected());
        fprintf(stdout, "[%s] WatchEnd\r\n", IsSelected());
        fprintf(stdout, "[%s] GetFocus\t\t", IsSelected());
        fprintf(stdout, "[%s] SetFocus\r\n", IsSelected());
    }
    else
    {
        _gIndex = 0;
    }
    for (int effect = 1; effect <= MAX_SELECTION; ++effect)
    {
        fprintf(stdout, "[%s] Effect %d", IsSelected(), effect);
        if (effect % 5 == 0 ||
            effect == MAX_SELECTION)
        {
            fprintf(stdout, "\r\n");
        }
        else
        {
            fprintf(stdout, "\t\t");
        }
    }	

	fprintf(stdout, "\r\n");
	fprintf(stdout, "\r\n");
    if (_gSelection > 0)
    {
        fprintf(stdout, "[%d] Press ENTER to play selection. ", _gSelection);
    }
    else
    {
        fprintf(stdout, "[ ] Press ENTER to play selection. ");
    }

	fprintf(stdout, "\r\n");
	if (_gManualInput[0] != ' ')
	{
		fprintf(stdout, "%c", _gManualInput[0]);
		if (_gManualInput[1] != ' ')
		{
			fprintf(stdout, "%c", _gManualInput[1]);
		}
		fprintf(stdout, "\r\n");
	}
}

void ClearManualInput()
{
	_gManualInput[0] = ' ';
	_gManualInput[1] = ' ';
}

void ExecuteEffect(bool supportsStreaming, BYTE platform);

void Cleanup()
{
	if (ChromaAnimationAPI::GetIsInitializedAPI())
	{
		if (ChromaAnimationAPI::IsInitialized())
		{
			ChromaAnimationAPI::StopAll();
			ChromaAnimationAPI::CloseAll();
			RZRESULT result = ChromaAnimationAPI::Uninit();
			ChromaAnimationAPI::UninitAPI();
			if (result != RZRESULT_SUCCESS)
			{
				cerr << "Failed to uninitialize Chroma!" << endl;
				exit(1);
			}
		}
	}
}

int main()
{
    fprintf(stderr, "App launched!\r\n");
    if (ChromaAnimationAPI::InitAPI() != RZRESULT_SUCCESS)
    {
        return -1;
    }

    ChromaSDK::APPINFOTYPE appInfo = {};

    _tcscpy_s(appInfo.Title, 256, _T("C++ Game Sample Application"));
    _tcscpy_s(appInfo.Description, 1024, _T("A sample application using Razer Chroma SDK"));
    _tcscpy_s(appInfo.Author.Name, 256, _T("Razer"));
    _tcscpy_s(appInfo.Author.Contact, 256, _T("https://developer.razer.com/chroma"));

    //appInfo.SupportedDevice = 
    //    0x01 | // Keyboards
    //    0x02 | // Mice
    //    0x04 | // Headset
    //    0x08 | // Mousepads
    //    0x10 | // Keypads
    //    0x20   // ChromaLink devices
    appInfo.SupportedDevice = (0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20);
    //    0x01 | // Utility. (To specifiy this is an utility application)
    //    0x02   // Game. (To specifiy this is a game);
    appInfo.Category = 1;

	RZRESULT result = ChromaAnimationAPI::InitSDK(&appInfo);
	if (result != RZRESULT_SUCCESS)
	{
		cerr << "Failed to initialize Chroma!" << endl;
		ChromaAnimationAPI::UninitAPI();
		exit(1);
	}
	Sleep(100); //wait for init

	bool supportsStreaming = ChromaAnimationAPI::CoreStreamSupportsStreaming();

    if (supportsStreaming)
    {
        _gSelection = -9;
    }

    // sample for getting the mapping between potential UI key binding enums and RZKEY
    RazerKeyboardMapping* mapping = RazerKeyboardMapping::GetInstance();
    int key = mapping->GetRZKEY(2);

    HandleInput numKeys[] =
    {
        HandleInput('0'),
        HandleInput('1'),
        HandleInput('2'),
        HandleInput('3'),
        HandleInput('4'),
        HandleInput('5'),
        HandleInput('6'),
        HandleInput('7'),
        HandleInput('8'),
        HandleInput('9'),
    };

    HandleInput numpadKeys[] =
    {
        HandleInput(VK_NUMPAD0),
        HandleInput(VK_NUMPAD1),
        HandleInput(VK_NUMPAD2),
        HandleInput(VK_NUMPAD3),
        HandleInput(VK_NUMPAD4),
        HandleInput(VK_NUMPAD5),
        HandleInput(VK_NUMPAD6),
        HandleInput(VK_NUMPAD7),
        HandleInput(VK_NUMPAD8),
        HandleInput(VK_NUMPAD9),
    };

	BYTE platform = 0;

    PrintLegend(supportsStreaming, platform);
    HandleInput inputUp = HandleInput(VK_UP);
    HandleInput inputDown = HandleInput(VK_DOWN);
    HandleInput inputBackspace = HandleInput(VK_BACK);
    HandleInput inputEnter = HandleInput(VK_RETURN);
	HandleInput inputPlatform = HandleInput('P');
    HandleInput inputEscape = HandleInput(VK_ESCAPE);

    int autoPrint = 0;

    while (true)
    {
        if (++autoPrint > 100)
        {
            autoPrint = 0;
            PrintLegend(supportsStreaming, platform);
        }

        if (inputEscape.WasReleased(true))
        {
            ChromaAnimationAPI::StopAll();
            ChromaAnimationAPI::CloseAll();
            ChromaAnimationAPI::ClearAll();
            ChromaAnimationAPI::Uninit();
            break;
        }
		else if (inputPlatform.WasReleased(true))
		{
			ClearManualInput();
			platform = (platform + 1) % 4; //PC, AMAZON LUNA, MS GAME PASS, NVIDIA GFN
			PrintLegend(supportsStreaming, platform);
		}
        else if (inputUp.WasReleased(true))
        {
            ClearManualInput();
            if (supportsStreaming && _gSelection > -9)
            {
                --_gSelection;
            }
			else if (_gSelection > 1)
			{
				--_gSelection;
			}
			PrintLegend(supportsStreaming, platform);
			if (_gSelection >= 1)
            {
                ExecuteEffect(supportsStreaming, platform);
            }
		}
		

		else if (inputDown.WasReleased(true))
		{
			ClearManualInput();
			if (_gSelection < MAX_SELECTION)
			{
				_gSelection++;
			}
			PrintLegend(supportsStreaming, platform);
            if (_gSelection > 1)
            {
                ExecuteEffect(supportsStreaming, platform);
            }
		}

		bool hasManualInput = false;
		if (inputBackspace.WasReleased(true))
		{
			if (_gManualInput[1] != ' ')
			{
				_gManualInput[1] = ' ';
				hasManualInput = true;

			}
			else if (_gManualInput[0] != ' ')
			{
				_gManualInput[0] = ' ';
				hasManualInput = true;
			}
		}
		for (int i = 0; i < (int)size(numKeys); ++i)
		{
			if (numKeys[i].WasReleased(true) ||
				numpadKeys[i].WasReleased(true))
			{
				if (_gManualInput[0] != ' ')
				{
					_gManualInput[1] = numKeys[i].GetKey();
					hasManualInput = true;
				}
				else
				{
					_gManualInput[0] = numKeys[i].GetKey();
					hasManualInput = true;
				}
			}
		}
		if (hasManualInput)
		{
			int val = 0;
			if (_gManualInput[1] != ' ')
			{
				if (_gManualInput[0] >= '0' && _gManualInput[0] <= '9')
				{
					val = 10 * (_gManualInput[0] - '0');
				}
				if (_gManualInput[1] >= '0' && _gManualInput[1] <= '9')
				{
					val += _gManualInput[1] - '0';
				}
			}
			else if (_gManualInput[0] != ' ')
			{
				val = _gManualInput[0] - '0';
			}
			if (val <= MAX_SELECTION)
			{
				_gSelection = val;
			}
			PrintLegend(supportsStreaming, platform);
		}

		if (inputEnter.WasReleased(true))
		{
			PrintLegend(supportsStreaming, platform);
			ClearManualInput();

            ExecuteEffect(supportsStreaming, platform);

            if (_gSelection < 1)
            {
                PrintLegend(supportsStreaming, platform);
            }
		}
		Sleep(1);
	}

	Cleanup();

    return 0;
}

void ExecuteEffect(bool supportsStreaming, BYTE platform)
{
	// get current time
	high_resolution_clock::time_point timer = high_resolution_clock::now();

	switch (_gSelection)
	{
    case -9:
        if (supportsStreaming)
        {
			wstring strPlatform = L"PC";
			switch (platform)
			{
			case 0:
				strPlatform = L"PC";
				break;
			case 1:
				strPlatform = L"LUNA";
				break;
			case 2:
				strPlatform = L"GEFORCE_NOW";
				break;
			case 3:
				strPlatform = L"GAME_PASS";
				break;
			}
            ChromaAnimationAPI::CoreStreamGetAuthShortcode(_gShortcode, &_gLenShortcode, strPlatform.c_str(), L"CSDK Sample App 好");
        }
        break;
    case -8:
        if (supportsStreaming && _gLenShortcode > 0)
        {
            ChromaAnimationAPI::CoreStreamGetId(_gShortcode, _gStreamId, &_gLenStreamId);
        }
        break;
    case -7:
        if (supportsStreaming && _gLenShortcode > 0)
        {
            ChromaAnimationAPI::CoreStreamGetKey(_gShortcode, _gStreamKey, &_gLenStreamKey);
        }
        break;
    case -6:
        if (supportsStreaming && _gLenShortcode > 0)
        {
            if (ChromaAnimationAPI::CoreStreamReleaseShortcode(_gShortcode))
            {
                memset(_gShortcode, 0, size(_gShortcode));
                _gLenShortcode = 0;
            }
        }
        break;
    case -5:
        if (supportsStreaming &&
            _gLenStreamId > 0 && _gLenStreamKey > 0)
        {
            ChromaAnimationAPI::CoreStreamBroadcast(_gStreamId, _gStreamKey);
        }
        break;
    case -4:
        if (supportsStreaming)
        {
            ChromaAnimationAPI::CoreStreamBroadcastEnd();
        }
        break;
    case -3:
        if (supportsStreaming &&
            _gLenStreamId > 0)
        {
            unsigned long long timestamp = 0;
            ChromaAnimationAPI::CoreStreamWatch(_gStreamId, timestamp);
        }
        break;
    case -2:
        if (supportsStreaming)
        {
            ChromaAnimationAPI::CoreStreamWatchEnd();
        }
        break;
    case -1:
        if (supportsStreaming)
        {
            ChromaAnimationAPI::CoreStreamGetFocus(g_Focus, &g_LenFocus);
        }
        break;
    case 0:
        if (supportsStreaming)
        {
            ChromaAnimationAPI::CoreStreamSetFocus(g_FocusGuid);
            ChromaAnimationAPI::CoreStreamGetFocus(g_Focus, &g_LenFocus);
        }
        break;
    case 1:
        ShowEffect1();
        ShowEffect1ChromaLink();
        ShowEffect1Headset();
        ShowEffect1Keypad();
        ShowEffect1Mousepad();
        ShowEffect1Mouse();
        break;
    case 2:
        ShowEffect2();
        ShowEffect2ChromaLink();
        ShowEffect2Headset();
        ShowEffect2Keypad();
        ShowEffect2Mousepad();
        ShowEffect2Mouse();
        break;
    case 3:
        ShowEffect3();
        ShowEffect3ChromaLink();
        ShowEffect3Headset();
        ShowEffect3Keypad();
        ShowEffect3Mousepad();
        ShowEffect3Mouse();
        break;
    case 4:
        ShowEffect4();
        ShowEffect4ChromaLink();
        ShowEffect4Headset();
        ShowEffect4Keypad();
        ShowEffect4Mousepad();
        ShowEffect4Mouse();
        break;
    case 5:
        ShowEffect5();
        ShowEffect5ChromaLink();
        ShowEffect5Headset();
        ShowEffect5Keypad();
        ShowEffect5Mousepad();
        ShowEffect5Mouse();
        break;
    case 6:
        ShowEffect6();
        ShowEffect6ChromaLink();
        ShowEffect6Headset();
        ShowEffect6Keypad();
        ShowEffect6Mousepad();
        ShowEffect6Mouse();
        break;
    case 7:
        ShowEffect7();
        ShowEffect7ChromaLink();
        ShowEffect7Headset();
        ShowEffect7Keypad();
        ShowEffect7Mousepad();
        ShowEffect7Mouse();
        break;
    case 8:
        ShowEffect8();
        ShowEffect8ChromaLink();
        ShowEffect8Headset();
        ShowEffect8Keypad();
        ShowEffect8Mousepad();
        ShowEffect8Mouse();
        break;
    case 9:
        ShowEffect9();
        ShowEffect9ChromaLink();
        ShowEffect9Headset();
        ShowEffect9Keypad();
        ShowEffect9Mousepad();
        ShowEffect9Mouse();
        break;
    case 10:
        ShowEffect10();
        ShowEffect10ChromaLink();
        ShowEffect10Headset();
        ShowEffect10Keypad();
        ShowEffect10Mousepad();
        ShowEffect10Mouse();
        break;
    case 11:
        ShowEffect11();
        ShowEffect11ChromaLink();
        ShowEffect11Headset();
        ShowEffect11Keypad();
        ShowEffect11Mousepad();
        ShowEffect11Mouse();
        break;
    case 12:
        ShowEffect12();
        ShowEffect12ChromaLink();
        ShowEffect12Headset();
        ShowEffect12Keypad();
        ShowEffect12Mousepad();
        ShowEffect12Mouse();
        break;
    case 13:
        ShowEffect13();
        ShowEffect13ChromaLink();
        ShowEffect13Headset();
        ShowEffect13Keypad();
        ShowEffect13Mousepad();
        ShowEffect13Mouse();
        break;
    case 14:
        ShowEffect14();
        ShowEffect14ChromaLink();
        ShowEffect14Headset();
        ShowEffect14Keypad();
        ShowEffect14Mousepad();
        ShowEffect14Mouse();
        break;
    case 15:
        ShowEffect15();
        ShowEffect15ChromaLink();
        ShowEffect15Headset();
        ShowEffect15Keypad();
        ShowEffect15Mousepad();
        ShowEffect15Mouse();
        break;
	}

	// get time in seconds
	duration<double, milli> time_span = high_resolution_clock::now() - timer;
	float deltaTime = (float)(time_span.count() / 1000.0f);
	fprintf(stdout, "Elapsed time: %f\r\n\r\n", deltaTime);
}
