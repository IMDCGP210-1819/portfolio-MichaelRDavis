#include "BehaviorTree.h"
#include "Composites/Sequence.h"
#include "Test/TestBehavior.h"

int main()
{
	std::unique_ptr<BehaviorTree> testTree = std::make_unique<BehaviorTree>();
	auto testSequence = std::make_shared<Sequence>();
	auto testTask = std::make_shared<TestBehavior>();

	testSequence->AddChildren(testTask);
	testTree->SetRootNode(testSequence);
	testTree->OnTick();

	return 0;
}