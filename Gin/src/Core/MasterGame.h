#pragma once

#include "..\GinPch.h"

#include "..\Graphics\Screen.h"
#include "..\Graphics\Renderer.h"
#include "..\Inputs\Processor.h"

constexpr auto FPS_REFRESH_RATE = 0.25;
constexpr auto UPDATE_TIME_STEP = 1666667;
constexpr auto TICKS_IN_SECOND = 10000000;

namespace Gin
{
	namespace Core
	{
		using namespace Graphics;
		using namespace Inputs;
		using namespace std::chrono;

		class MasterGame
		{
		public:
			MasterGame(float width = 640, float height = 480);
			~MasterGame();

			void Run();
			void SetTimeStep(int ticks);
			void SetTimeStep(double seconds);

			virtual void Update(Inputs::Processor *processor, float dt) {}
			virtual void Render(Graphics::Renderer *renderer, float dt) {}

		protected:
			virtual void Init() {}

		private:
			Graphics::Screen *screen;
			Inputs::Processor *inputProcessor;

			time_point<steady_clock> LastUpdateTime;
			time_point<steady_clock> LastRenderTime;
			time_point<steady_clock> LastFPSRefresh;
			uint64_t CumulativeDt; //In ticks
			uint64_t TargetTimeStep;
			uint64_t FramesElapsed;
		};
	} // namespace Core
} // namespace Gin