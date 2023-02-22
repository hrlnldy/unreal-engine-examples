#pragma once

/**
 * 为非Actor类增加Tick的功能
 */
class FMineTickableObject : public FTickableGameObject
{
public:
	virtual void Tick(float DeltaTime) override;
	virtual TStatId GetStatId() const override;
};
