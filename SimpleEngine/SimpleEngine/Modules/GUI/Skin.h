#ifndef UI_SKIN_H_
#define UI_SKIN_H_

#pragma once

#include <GUI/UICommon.h>

namespace SimpleEngine
{
	namespace UI
	{
		// �ؼ���Ƥ��, ����һ���ؼ�����Ⱦ
		class ISkin
		{
		public:
			ISkin() {}
			virtual ~ISkin() {}

			virtual void DoRender(Coord<int> bounds) = 0;

		private:

		};
	}
}

#endif // !UI_SKIN_H_