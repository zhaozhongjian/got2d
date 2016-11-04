#pragma once
#include "../include/g2dscene.h"
#include "entity.h"
#include <gmlmatrix.h>
#include <vector>

class SceneNode : public g2d::SceneNode
{
public:
	SceneNode(g2d::Scene* scene, SceneNode* parent, g2d::Entity* entity, bool autoRelease);
	virtual ~SceneNode();
	void Update(unsigned int elpasedTime);
	void Render(g2d::Camera* m_camera);

public:
	inline virtual g2d::Scene* GetScene() const override { return m_scene; }
	virtual g2d::SceneNode* CreateSceneNode(g2d::Entity* entity, bool autoRelease)override;
	virtual const gml::mat32& GetLocalMatrix() override;
	virtual const gml::mat32& GetWorldMatrix() override;
	virtual void SetVisibleMask(unsigned int mask, bool recursive) override;
	virtual g2d::SceneNode* SetPosition(const gml::vec2& position) override;
	virtual g2d::SceneNode* SetPivot(const gml::vec2& pivot) override;
	virtual g2d::SceneNode* SetScale(const gml::vec2& scale) override;
	virtual g2d::SceneNode* SetRotation(float radian) override;
	inline virtual void SetVisible(bool visible) override { m_isVisible = visible; }
	inline virtual const gml::vec2& GetPosition()  const override { return m_position; }
	inline virtual const gml::vec2& GetPivot() const override { return m_pivot; }
	inline virtual const gml::vec2& GetScale() const override { return m_scale; }
	inline virtual float GetRotation() const override { return m_rotationRadian; }
	inline virtual g2d::Entity* GetEntity() const override { return m_entity; }
	inline virtual bool IsVisible() const override { return m_isVisible; }
	inline virtual unsigned int GetVisibleMask() const override { return m_visibleMask; }

private:
	void SetLocalMatrixDirty();
	void SetWorldMatrixDirty();

	g2d::Scene* m_scene = nullptr;
	::SceneNode* m_parent = nullptr;
	g2d::Entity* m_entity = nullptr;

	unsigned int m_visibleMask = g2d::DEFAULT_VISIBLE_MASK;
	bool m_autoRelease = false;
	bool m_isVisible = true;

	gml::vec2 m_position;
	gml::vec2 m_pivot;
	gml::vec2 m_scale;
	float m_rotationRadian = 0;

	bool m_matrixDirtyUpdate = false;
	bool m_matrixLocalDirty = false;
	bool m_matrixWorldDirty = true;
	gml::mat32 m_matrixLocal;
	gml::mat32 m_matrixWorld;
	std::vector<::SceneNode*> m_children;
};

class Scene : public g2d::Scene
{
public:
	Scene();
	~Scene();

	inline ::SceneNode* GetRoot() { return m_root; }
	inline void Update(unsigned int elpasedTime) { return m_root->Update(elpasedTime); }
	void Render();
	void SetRenderingOrderDirty();

public:
	inline virtual g2d::Scene* GetScene() const override { return m_root->GetScene(); }
	inline virtual g2d::SceneNode* CreateSceneNode(g2d::Entity* e, bool autoRelease) override { return m_root->CreateSceneNode(e, autoRelease); }
	inline virtual const gml::mat32& GetLocalMatrix() override { return m_root->GetLocalMatrix(); }
	inline virtual const gml::mat32& GetWorldMatrix() override { return m_root->GetWorldMatrix(); }
	inline virtual void SetVisibleMask(unsigned int mask, bool recursive) override { m_root->SetVisibleMask(mask, recursive); }
	inline virtual g2d::SceneNode* SetPosition(const gml::vec2& position) override { m_root->SetPosition(position); return this; }
	inline virtual g2d::SceneNode* SetPivot(const gml::vec2& pivot) override { m_root->SetPivot(pivot); return this; }
	inline virtual g2d::SceneNode* SetScale(const gml::vec2& scale) override { m_root->SetScale(scale); return this; }
	inline virtual g2d::SceneNode* SetRotation(float radian) override { m_root->SetRotation(radian); return this; }
	inline virtual void SetVisible(bool visible) override { m_root->SetVisible(visible); }
	inline virtual const gml::vec2& GetPosition()  const override { return m_root->GetPosition(); }
	inline virtual const gml::vec2& GetPivot() const override { return m_root->GetPivot(); }
	inline virtual const gml::vec2& GetScale() const override { return m_root->GetScale(); }
	inline virtual float GetRotation() const override { return m_root->GetRotation(); }
	inline virtual g2d::Entity* GetEntity() const override { return m_root->GetEntity(); }
	inline virtual bool IsVisible() const override { return m_root->IsVisible(); }
	inline virtual unsigned int GetVisibleMask() const override { return m_root->GetVisibleMask(); }
public:
	virtual g2d::Camera* CreateCameraNode() override;
	virtual g2d::Camera* GetMainCamera() const override { return GetCamera(0); }
	virtual g2d::Camera* GetCamera(unsigned int index) const override;

private:
	void ResortCameraRenderingOrder();

	::SceneNode* m_root;
	std::vector<g2d::Camera*> m_cameras;
	std::vector<g2d::Camera*> m_renderingOrder;
	bool m_renderingOrderDirty;
};
