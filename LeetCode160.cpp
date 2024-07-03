if (!headA || !headB) return nullptr;

        ListNode *p = headA;
        ListNode *q = headB;

        while (p != q) {
            if (p) {
                p = p->next;
            } else {
                p = headB;
            }

            if (q) {
                q = q->next;
            } else {
                q = headA;
            }
        }

        return p;
    }
