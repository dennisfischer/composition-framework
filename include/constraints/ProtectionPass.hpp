#ifndef CONSTRAINT_HANDLER_PROTECTIONPASS_HPP
#define CONSTRAINT_HANDLER_PROTECTIONPASS_HPP

#include "llvm/Pass.h"

class ProtectionPass : public llvm::ModulePass {
public:
	static char ID;
public:
	ProtectionPass() : ModulePass(ID) {}

	void getAnalysisUsage(llvm::AnalysisUsage &AU) const override;

	bool runOnModule(llvm::Module &M) override;
};


#endif //CONSTRAINT_HANDLER_PROTECTIONPASS_HPP
