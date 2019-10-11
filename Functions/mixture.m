function [ label_m ] = mixture( label,label_Pseudo,mr )
% 掺混正常标签与伪标签
% [掺混后的标签] = mixture(标签，伪标签，掺混比例)

[~,nl] = size(label);
k = rand(1,nl);
[~,n] = sort(k);

label_Pseudo(:,n(1:mr*nl)) = label(:,n(1:mr*nl));

label_m = label_Pseudo;

end

