﻿#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class InfoText
	{
	public:
		String^ testMVR = "Для решения тестовой задачи использованы сетка с числом разбиений по x \
n = % и числом разбиений по y m = %, \
метод верхней релаксации с параметром ω = %, применены критерии\
остановки по точности εмет = % и по числу итераций Nmax = % \
На решение схемы (СЛАУ) затрачено итераций N = % и достигнута точ- \
ность итерационного метода ε(N) = % \
Схема (СЛАУ) решена с невязкой ||R(N)||2 = % (указать норму невязки) \
Тестовая задача должна быть решена с погрешностью не более ε = 0.5⋅10 –6; \
задача решена с погрешностью ε1 =% \
Максимальное отклонение точного и численного решений наблюдается в уз- \
ле x=%; y=% \
В качестве начального приближения использовано %";
	};
}


