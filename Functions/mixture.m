function [ label_m ] = mixture( label,label_Pseudo,mr )
% ����������ǩ��α��ǩ
% [�����ı�ǩ] = mixture(��ǩ��α��ǩ���������)

[~,nl] = size(label);
k = rand(1,nl);
[~,n] = sort(k);

label_Pseudo(:,n(1:mr*nl)) = label(:,n(1:mr*nl));

label_m = label_Pseudo;

end

