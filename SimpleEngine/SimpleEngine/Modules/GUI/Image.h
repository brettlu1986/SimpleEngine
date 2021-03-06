////////////////////////////////////////////////////////////////////////////////
// Filename: bitmapclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef UI_IMAGE_H_
#define UI_IMAGE_H_

#pragma once

#include <d3d11.h>
#include <d3dx10math.h>

#include "textureclass.h"
#include <GUI/Skin.h>
#include <Graphics/textureshaderclass.h>

namespace SimpleEngine
{
	namespace UI
	{
		// 2D Image = 3D object, texture = ģ����ͼ
		class Image : public ISkin
		{
		private:
			struct VertexType
			{
				D3DXVECTOR3 position;
				D3DXVECTOR2 texture;
			};

		public:
			Image(WCHAR const * textureFilename);
			Image(Image const &);
			~Image();

			void DoRender(Rect<int> bounds) override;

			int GetIndexCount();
			ID3D11ShaderResourceView* GetTexture();

		private:
			bool InitializeBuffers();
			void ShutdownBuffers();
			bool RebuildBuffers(Rect<int> bounds);
			void RenderBuffers();

			bool LoadTexture(WCHAR const *);
			void ReleaseTexture();

			bool InitializeShader();

		private:
			ID3D11Buffer *m_vertexBuffer{ nullptr }, *m_indexBuffer{ nullptr };
			int m_vertexCount, m_indexCount;
			TextureClass* m_Texture{ nullptr };
			TextureShaderClass* m_TextureShader{ nullptr };

			Rect<int> image_bounds_;
		};
	}
}

#endif // UI_IMAGE_H_